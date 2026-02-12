/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoka <vpoka@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:57:25 by vpoka             #+#    #+#             */
/*   Updated: 2026/02/11 17:08:33 by vpoka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>

class Data;

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer &other);
	Serializer	&operator=(const Serializer &other);
	~Serializer(void);
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif /* SERIALIZER_HPP */
