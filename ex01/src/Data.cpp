/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:49:31 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/11 17:41:24 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "debug.hpp"

/**
 * @brief default constructor
*/
Data::Data(void):
	name_("default"),
	cooked_(false),
	age_(69)
{
	DEBUG_MSG("Data default constructor called");
}

/**
 * @brief parameterized constructor
*/
Data::Data(const std::string& name, bool cooked, int age):
	name_(name),
	cooked_(cooked),
	age_(age)
{
	DEBUG_MSG("Data parameterized constructor called");
}

/**
 * @brief copy constructor
 * 
 * @param other object to copy
*/
Data::Data(const Data &other):
	name_(other.getName()),
	cooked_(other.getCook()),
	age_(other.getAge())
{
	DEBUG_MSG("Data copy constructor called");
}

/**
 * @brief destructor
*/
Data::~Data(void)
{
	DEBUG_MSG("Data destructor called");
}

/**
 * @brief assignment operator
 * 
 * @param other object to assign from
 * 
 * @return reference to 'this' object
 *
 * @note does nothing as data is const
*/
Data	&Data::operator=(const Data &other)
{
	DEBUG_MSG("Data assignment operator called");
	(void)other;
	return (*this);
}

const std::string& Data::getName(void) const
{
	return (this->name_);
}
bool Data::getCook(void) const
{
	return (this->cooked_);
}

int Data::getAge(void) const
{
	return (this->age_);
}

void	Data::setName(const std::string& new_name)
{
	this->name_ = new_name;
}

void	Data::setCook(bool now_cooked)
{
	this->cooked_ = now_cooked;
}
void	Data::setAge(int the_new_age)
{
	this->age_ = the_new_age;
}

/** 
 * @brief output stream operator
 * 
 * @param os reference to the outputstream
 * @param class reference to the class object
 * 
 * @return reference to the output stream
*/
std::ostream	&operator<<(std::ostream &os, const Data &c)
{
	os << "name: " << c.getName() \
	<< "\ncooked? " << (c.getCook() ? "yes" : "no") \
	<< "\nage: " << c.getAge() \
	<< "\naddress: " << &c << std::endl;
	return (os);
}
