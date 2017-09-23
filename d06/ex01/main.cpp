/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

Data*	deserialize(void *raw)
{
	Data *d = serializer::getInstance()->get_data();
	d->s1 = reinterpret_cast<char *>(raw);
	d->s2 = d->s1.substr(d->s1.length() - 8, d->s1.length());
	int length =  d->s1.length() - 16;
	d->n = std::atoi(d->s1.substr(8, length).c_str());
	d->s1 = d->s1.substr(0, 8);
	return (d);
}

void*	serialize(void)
{
	const char *list = const_cast<char *>(serializer::getInstance()->get_alphanumeric());
	int i = -1;

	std::string str;
	while (++i < 8)
	{
		int num = std::rand() % serializer::getInstance()->get_list().length();
		str.push_back(list[num]);
	}
	std::string rand_int = std::to_string(rand() % INT_MAX);
	str += rand_int;
	i = -1;
	while (++i < 8)
	{
		int num = std::rand() % serializer::getInstance()->get_list().length();
		str.push_back(list[num]);
	}
	return reinterpret_cast<void *>(const_cast<char *>(str.c_str()));
}

int		main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	void *s = serialize();
	std::cout << "Data memory adress: " << s << std::endl;
	std::cout << "Serialized data: "  << reinterpret_cast<char *>(s) << std::endl;
	std::cout << "Deserialized data: " << std::endl;
	Data *d = deserialize(s);
	std::cout << "first string: " << d->s1 << std::endl;
	std::cout << "integer: " << d->n << std::endl;
	std::cout << "second string: " << d->s2 << std::endl;
	return (0);
}
