/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 23:30:13 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/12 12:27:23 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "debug.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <stdexcept>

static void printTest(int test_num, std::string message)
{
	std::cout << BLUE << "\n--" << RESET \
	<< BOLDBLUE << " [TEST " << test_num << "]" << RESET \
	<< BLUE << " - '" << message << "' --\n" << RESET << std::endl;
}

static void announceCreation(const std::string& object_class)
{
	std::cout << "created '" << object_class << "'" << std::endl;
}

static void announcePointer(const std::string& object_class)
{
	std::cout << "identified<*> '" << object_class << "'" << std::endl;
}

static void announceReference(const std::string& object_class)
{
	std::cout << "identified<&> '" << object_class << "'" << std::endl;
}

Base*	generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			announceCreation("A");
			return (new A);
		case 1:
			announceCreation("B");
			return (new B);
		case 2:
			announceCreation("C");
			return (new C);
		default:
			throw std::runtime_error("runtime_error: failed to generate Base<*>");
	}
	return (NULL);
}

void identify(Base* p)
{
	DEBUG_MSG("identifying Base<*>\n");

	if (dynamic_cast<A*>(p) != NULL)
		announcePointer("A");
	else if (dynamic_cast<B*>(p) != NULL)
		announcePointer("B");
	else if (dynamic_cast<C*>(p) != NULL)
		announcePointer("C");
	else
		throw std::runtime_error("runtime_error: failed to identify Base<*>");
}

void identify(Base& p)
{
	DEBUG_MSG("identifying Base<&>\n");

	try
	{
		(void)dynamic_cast<A&>(p);
		announceReference("A");
		return ;
	} catch (const std::exception& e)
	{
		DEBUG_MSG("Base<&> is not A\n");
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		announceReference("B");
		return ;
	} catch (const std::exception& e)
	{
		DEBUG_MSG("Base<&> is not B\n");
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		announceReference("C");
		return ;
	} catch (const std::exception& e)
	{
		DEBUG_MSG("Base<&> is not C\n");
	}

	throw std::runtime_error("runtime_error: failed to identify Base<&>");
}

static void test1(void)
{
	printTest(1, "identify random derived Base<*> object");

	try
	{
		Base* b = generate(); // generate random object (A/B/C)

		identify(b); // identify by pointer
		identify(*b); // identify by reference
		delete b;
	} catch (const std::exception& e)
	{
		ERROR_MSG("exception caught: ");
		std::cerr << e.what() << std::endl;
	}
}

static void test2(void)
{
	printTest(2, "identify multiple random derived Base<*> objects");

	try
	{
		std::cout << MAGENTA << " -- 1 -- " << RESET << std::endl;
		Base* b = generate();

		identify(b);
		identify(*b);
		delete b;

		std::cout << MAGENTA << " -- 2 -- " << RESET << std::endl;
		b = generate();

		identify(b);
		identify(*b);
		delete b;

		std::cout << MAGENTA << " -- 3 -- " << RESET << std::endl;
		b = generate();

		identify(b);
		identify(*b);
		delete b;

		std::cout << MAGENTA << " -- 4 -- " << RESET << std::endl;
		b = generate();

		identify(b);
		identify(*b);
		delete b;
	} catch (const std::exception& e)
	{
		ERROR_MSG("exception caught: ");
		std::cerr << e.what() << std::endl;
	}
}

static void test3(void)
{
	printTest(3, "identify Base object (error)");
	
	Base b; // standard Base obj

	try
	{
		identify(&b); // identify by pointer
	} catch (const std::exception& e)
	{
		ERROR_MSG("exception caught: ");
		std::cerr << e.what() << std::endl;
	}

	try
	{
		identify(b); // identify by reference
	} catch (const std::exception& e)
	{
		ERROR_MSG("exception caught: ");
		std::cerr << e.what() << std::endl;
	}
}

static void test4(void)
{
	printTest(4, "identify Base<*> object (error)");

	Base* b = new Base(); // standard Base pointer obj

	try
	{
		identify(b); // identify by pointer
	} catch (const std::exception& e)
	{
		ERROR_MSG("exception caught: ");
		std::cerr << e.what() << std::endl;
	}

	try
	{
		identify(*b); // identify by reference
	} catch (const std::exception& e)
	{
		ERROR_MSG("exception caught: ");
		std::cerr << e.what() << std::endl;
	}
	delete b;
}

int	main(void)
{
	// create seed
	std::srand(std::time(0));
	test1();
	test2();
	test3();
	test4();
	return (0);
}
