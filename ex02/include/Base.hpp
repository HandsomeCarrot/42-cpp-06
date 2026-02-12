/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:04:14 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/12 02:29:57 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include "debug.hpp"

class Base
{
public:
	virtual ~Base(void) {DEBUG_MSG("Base deconstructor called\n");}
};

#endif /* BASE_HPP */
