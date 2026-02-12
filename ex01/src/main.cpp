/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:38:10 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/11 18:59:05 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "colors.h"
#include "Data.hpp"
#include <iomanip>

static void printTest(int test_num, std::string message)
{
	std::cout << BLUE << "\n--" << RESET \
	<< BOLDBLUE << " [TEST " << test_num << "]" << RESET \
	<< BLUE << " - '" << message << "' --\n" << RESET << std::endl;
}

static void printSeparator(int descWidth, int colWidth)
{
	std::cout << std::string(descWidth, '-') << "+"
			<< std::string(colWidth, '-') << "+"
			<< std::string(colWidth, '-') << std::endl;
}

static void compareData(const Data& original, const Data& deserialized)
{
	const int colWidth = 20;
	const int descWidth = 10;

	std::cout << std::left << std::setw(descWidth) << " " << "|"
			<< MAGENTA << std::setw(colWidth) << " original" << RESET << "|"
			<< MAGENTA << std::setw(colWidth) << " deserialized" << RESET << std::endl;
	
	printSeparator(descWidth, colWidth);
	
	std::cout << MAGENTA << std::left << std::setw(descWidth) << " name" << RESET << "|"
			<< std::setw(colWidth) << original.getName() << "|"
			<< deserialized.getName() << std::endl;
	
	printSeparator(descWidth, colWidth);
	
	std::cout << MAGENTA << std::left << std::setw(descWidth) << " cooked" << RESET << "|"
			<< std::setw(colWidth) << (original.getCook() ? "yes" : "no") << "|"
			<< (deserialized.getCook() ? "yes" : "no") << std::endl;
	
	printSeparator(descWidth, colWidth);
	
	std::cout << MAGENTA << std::left << std::setw(descWidth) << " age" << RESET << "|"
			<< std::setw(colWidth) << original.getAge() << "|"
			<< deserialized.getAge() << std::endl;
	
	printSeparator(descWidth, colWidth);
	
	std::cout << MAGENTA << std::left << std::setw(descWidth) << " address" << RESET << "|"
			<< std::setw(colWidth) << &original << "|"
			<< &deserialized << std::endl;
}

static void test1(void)
{
	printTest(1, "still the same");

	Data d("one", false, 1);
	uintptr_t serialized = Serializer::serialize(&d);
	Data* deserialzed = Serializer::deserialize(serialized);

	compareData(d, *deserialzed);
}

static void test2(void)
{
	printTest(2, "changes affect everyone");

	Data d("two", false, 2);
	uintptr_t serialized = Serializer::serialize(&d);
	Data* deserialzed = Serializer::deserialize(serialized);

	compareData(d, *deserialzed);

	std::cout << BOLDYELLOW << "\nmanipulating data\n..." << RESET << std::endl;
	deserialzed->setName("ALBerTIcus");
	deserialzed->setCook(true);
	deserialzed->setAge(69);
	std::cout << BOLDYELLOW << "done\n" << RESET << std::endl;

	compareData(d, *deserialzed);
}

int	main(void)
{
	test1();
	test2();
	return (0);
}
