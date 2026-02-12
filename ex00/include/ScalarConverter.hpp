/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:05:53 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/09 15:24:47 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter	&operator=(const ScalarConverter &other);
	~ScalarConverter(void);
public:
	static void convert(std::string literal);
};

#endif /* SCALARCONVERTER_HPP */
