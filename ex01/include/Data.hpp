/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:49:27 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/11 17:43:57 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
private:
	std::string	name_;
	bool 			cooked_;
	int 			age_;
public:
	Data(void);
	Data(const std::string& name, bool cooked, int age);
	Data(const Data &other);
	Data	&operator=(const Data &other);
	~Data(void);

	const std::string&	getName(void) const;
	bool				getCook(void) const;
	int					getAge(void) const;

	void	setName(const std::string& new_name);
	void	setCook(bool now_cooked);
	void	setAge(int the_new_age);
};

std::ostream	&operator<<(std::ostream &os, const Data &c);

#endif /* DATA_HPP */
