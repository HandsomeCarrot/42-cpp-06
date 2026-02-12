/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 22:15:00 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/10 13:59:18 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_HPP
# define DEBUG_HPP

# include "colors.h"
# include <iostream>

# ifdef DEBUG
#  define DEBUG_MSG(x) std::cout << BOLDYELLOW << "[DEBUG] " << RESET << x << std::endl
# else
#  define DEBUG_MSG(x)
# endif

# define ERROR_MSG(x) std::cerr << BOLDRED << "[ERROR] " << RESET << x << std::endl
# define WARNING_MSG(x) std::cerr << YELLOW << "[WARNING] " << RESET << x << std::endl
# define INFO_MSG(x) std::cout << BOLDCYAN << "[INFO] " << RESET << x << std::endl
# define SUCCESS_MSG(x) std::cout << BOLDGREEN << "[SUCCESS] " << RESET << x << std::endl


#endif /* DEBUG_HPP */

