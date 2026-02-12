/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:05:49 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/11 13:11:51 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "debug.hpp"
#include <cstdlib>
#include <ios>
#include <iostream>
#include <cctype>
#include <sstream>
#include <iomanip>

/**
 * @brief Enumeration representing the original type state of a literal.
 *
 * options:
 *    - CHAR
 *    - INT
 *    - FLOAT
 *    - DOUBLE
 */
typedef enum	e_original_state
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}				t_original_state;

/**
 * @brief Prints a type label with left-aligned formatting.
 *
 * @param type The type name to display (e.g., "char", "int").
 */
static void printType(const std::string& type)
{
	std::cout << std::left << std::setw(10) << type << ": ";
}

/**
 * @brief Prints the detected state marker if this is the original type.
 *
 * @param state The current type state being printed.
 * @param original_state The original type state of the literal.
 */
static void printState(t_original_state state, t_original_state original_state)
{
	if (state == original_state)
		std::cout << " (detected)";
	std::cout << std::endl;
}

/**
 * @brief Prints the char representation of a converted value.
 *
 * @param c The char value to display.
 * @param pseudo_literal Whether the literal is a pseudo-literal (nan/inf).
 */
static void printChar(char c, bool pseudo_literal)
{
	printType("char");

	if (pseudo_literal)
		std::cout << "impossible";
	else if (!std::isprint(c))
		std::cout << "non displayable";
	else
		std::cout << "'" << c << "'";
}

/**
 * @brief Prints the int representation of a converted value.
 *
 * @param i The int value to display.
 * @param pseudo_literal Whether the literal is a pseudo-literal (nan/inf).
 */
static void printInt(int i, bool pseudo_literal)
{
	printType("int");

	if (pseudo_literal)
		std::cout << "impossible";
	else
		std::cout << i;
}

/**
 * @brief Prints the float representation of a converted value.
 *
 * @param f The float value to display.
 */
static void printFloat(float f)
{
	printType("float");

	std::cout << std::fixed << std::setprecision(1) << f << "f";
	
}

/**
 * @brief Prints the double representation of a converted value.
 *
 * @param d The double value to display.
 */
static void printDouble(double d)
{
	printType("double");

	std::cout << std::fixed << std::setprecision(1) << d;
	
}

/**
 * @brief Prints the full conversion output for all scalar types.
 *
 * @param c The char value.
 * @param i The int value.
 * @param f The float value.
 * @param d The double value.
 * @param state The original type state to mark detected type.
 * @param pseudo_literal Whether the literal is a pseudo-literal.
 */
static void printConversion(char c, int i, float f, double d, t_original_state state, bool pseudo_literal)
{
	printChar(c, pseudo_literal);
	printState(CHAR, state);

	printInt(i, pseudo_literal);
	printState(INT, state);

	printFloat(f);
	printState(FLOAT, state);

	printDouble(d);
	printState(DOUBLE, state);
}

/**
 * @brief Converts an int literal and prints all scalar type conversions.
 *
 * @param literal The string literal to convert.
 */
static void convertInt(const std::string& literal)
{
	int i =  static_cast<int>(std::strtol(literal.c_str(), NULL, 10));

	printConversion(static_cast<char>(i), i, static_cast<float>(i), static_cast<double>(i), INT, false);
}

/**
 * @brief Converts a char literal and prints all scalar type conversions.
 *
 * @param literal The string literal containing a single character.
 */
static void convertChar(const std::string& literal)
{
	char c = static_cast<char>(literal[0]);

	printConversion(c, static_cast<int>(c), static_cast<float>(c), static_cast<double>(c), CHAR, false);
}

/**
 * @brief Converts a double literal and prints all scalar type conversions.
 *
 * @param literal The string literal to convert.
 * @param pseudo_literal Whether the literal is a pseudo-literal.
 */
static void convertDouble(const std::string& literal, bool pseudo_literal)
{
	double d = std::strtod(literal.c_str(), NULL);

	printConversion(static_cast<char>(d), static_cast<int>(d), static_cast<float>(d), d, DOUBLE, pseudo_literal);
}

/**
 * @brief Converts a float literal and prints all scalar type conversions.
 *
 * @param literal The string literal to convert.
 * @param pseudo_literal Whether the literal is a pseudo-literal.
 */
static void convertFloat(const std::string& literal, bool pseudo_literal)
{
	float f = static_cast<float>(std::strtod(literal.c_str(), NULL));

	printConversion(static_cast<char>(f), static_cast<int>(f), f, static_cast<double>(f), FLOAT, pseudo_literal);
}

/**
 * @brief Handles single character literals, determining if digit or char.
 *
 * @param literal The single-character string to handle.
 */
static void handleSingleChar(const std::string& literal)
{
	if (std::isdigit(literal[0]))
		convertInt(literal);
	else
		convertChar(literal);
}

/**
 * @brief Checks if a literal string is a pseudo-literal (NaN or infinity) and converts it accordingly.
 * 
 * @param literal The string literal to check and convert. Can be one of the following:
 *                - Float pseudo-literals: "nanf", "+inff", "-inff"
 *                - Double pseudo-literals: "nan", "+inf", "-inf"
 * 
 * @return true if the literal is a recognized pseudo-literal and conversion was performed,
 *         false otherwise.
 * 
 * @note This function performs a side effect by calling convertFloat() or convertDouble()
 *       when a matching pseudo-literal is found.
 */
static bool isPseudoLiteral(const std::string& literal)
{
	if (literal.compare("nanf") == 0 || literal.compare("+inff" ) == 0 || literal.compare("-inff") == 0) //pseudo-literals for float
		convertFloat(literal, true);
	else if (literal.compare("nan") == 0 || literal.compare("+inf") == 0 || literal.compare("-inf") == 0) //pseudo-literals for double
		convertDouble(literal, true);
	else
		return (false);
	return (true);
}

/**
 * @brief Skips consecutive digits in a string starting from a given position.
 * 
 * @param literal Reference to the string to process.
 * @param length The total length of the string.
 * @param pos The starting position from which to skip digits.
 * 
 * @return The position of the first non-digit character, or length if the end
 *         of the string is reached.
 */
static size_t skipDigits(const std::string& literal, size_t length, size_t pos)
{
	size_t i = pos;
	while (i < length && std::isdigit(literal[i]))
		i++;
	return (i);
}

/**
 * @brief Classifies and converts a numeric literal based on its format and characters.
 *
 * This static function analyzes a numeric literal string to determine its type
 * (int, float, or double) and delegates conversion to the appropriate handler function.
 * The function validates that the literal conforms to expected numeric formats.
 *
 * @param literal The numeric literal string to classify and convert.
 * @param length The total length of the literal string.
 * @param pos The current position being examined in the literal string.
 * @param decimal_point Boolean flag indicating whether a decimal point has been
 *                      encountered in the literal.
 *
 * @details
 * - If pos equals length, the entire string has been validated. If a decimal point
 *   was found, the literal is treated as a double; otherwise, as an int.
 * - If pos is at the last character and that character is 'f', the literal is
 *   converted as a float.
 * - If neither condition is met, the character at pos is invalid and an error
 *   message is generated indicating the invalid character and its position.
 *
 * @note This function calls ERROR_MSG() to report invalid characters found during
 *       classification.
 *
 * @see convertInt(), convertFloat(), convertDouble()
 */
static void classifyNumericLiteral(const std::string& literal, size_t length, size_t pos, bool decimal_point)
{
	if (pos == length)
	{
		if (decimal_point)
			convertDouble(literal, false);
		else
			convertInt(literal);
	}
	else if (pos == (length - 1) && literal[pos] == 'f')
		convertFloat(literal, false);
	else
	{
		std::stringstream msg;
		msg << "invalid character '" << literal[pos] << "' (char " << pos + 1 << ")";
		ERROR_MSG(msg.str());
	}
}

/**
 * @brief Parses and validates a numeric literal string.
 * 
 * Analyzes the input string to determine if it represents a valid numeric literal.
 * Handles optional signs (+/-), integer digits, and optional decimal points.
 * After parsing, classifies the literal and converts it to the appropriate type
 * (int, float, or double).
 * 
 * @param literal The numeric literal string to parse. Expected format:
 *                [+/-]digits[.digits]
 * 
 * @return void. Results are printed or error messages are displayed via
 *         classifyNumericLiteral().
 * 
 * @note This function is used internally for numeric conversion and classification.
 *       It does not return a value but delegates output handling to
 *       classifyNumericLiteral().
 */
static void parseNumericLiteral(const std::string& literal)
{
	const size_t length = literal.length();
	bool decimal_point = false;
	size_t pos = 0;

	// skip digits with optional sign (+/-)
	if (literal[pos] == '+' || literal[pos] == '-')
		pos++;
	pos = skipDigits(literal, length, pos);

	// skip optional decimal part (flag decimal point)
	if (pos < length && literal[pos] == '.')
	{
		decimal_point = true;
		pos = skipDigits(literal, length, ++pos);
	}

	// classify and convert to int/float/double, or print error
	classifyNumericLiteral(literal, length, pos, decimal_point);
}

/**
 * @brief Converts a scalar literal to all supported types and prints results.
 *
 * @param literal The string literal to convert and display.
 */
void ScalarConverter::convert(std::string literal)
{
	if (literal.empty())
		ERROR_MSG("literal is empty!");
	else if (literal.length() == 1)
		handleSingleChar(literal);
	else if(!isPseudoLiteral(literal))
		parseNumericLiteral(literal);
}
