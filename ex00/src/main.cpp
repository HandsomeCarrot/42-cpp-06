/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:23:40 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/10 15:27:55 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "colors.h"
#include "debug.hpp"

int	main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		ERROR_MSG("No input given!");
		return (1);
	}

	for (int i = 1; i < argc; i++)
	{
		std::cout << MAGENTA << " --- '" << argv[i] << "' --- " << RESET << std::endl;
		ScalarConverter::convert(argv[i]);
		std::cout << std::endl;
	}

	return (0);
}
