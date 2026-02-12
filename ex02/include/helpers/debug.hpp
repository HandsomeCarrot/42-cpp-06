/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 01:25:21 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/12 02:40:32 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_HPP
# define DEBUG_HPP

# include "colors.h"
# include <iostream>

# ifdef DEBUG
#  define DEBUG_MSG(x) std::cout << BOLDYELLOW << "[DEBUG] " << RESET << x;
# else
#  define DEBUG_MSG(x)
# endif

# define ERROR_MSG(x) std::cerr << BOLDRED << "[ERROR] " << RESET << x;
# define WARNING_MSG(x) std::cerr << YELLOW << "[WARNING] " << RESET << x;
# define INFO_MSG(x) std::cout << BOLDCYAN << "[INFO] " << RESET << x;
# define SUCCESS_MSG(x) std::cout << BOLDGREEN << "[SUCCESS] " << RESET << x;

#endif /* DEBUG_HPP */
