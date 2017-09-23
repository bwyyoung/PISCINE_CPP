/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY__
#define __ARRAY__

#include <iostream>
#include <stdexcept>

template <typename T>
class		Array
{
public:
	Array()
	{
		arr = new T[1];
	}
	~Array()
	{
		delete [] this->arr;
	}
	Array(unsigned int n)
	{
		this->arr_size = n;
		arr = new T[n];
	}

	Array(Array const & src)
	{
		*this = src;
	}

	Array &		operator=(Array const & src)
	{
		int			i = -1;
		if (this == &src)
			return *this;
		delete [] this->arr;
		this->arr_size = src.arr_size;
		this->arr = new T[this->arr_size];
		while (++i < this->arr_size)
			this->arr[i] = src.arr[i];
		return *this;
	}

	T&		operator[](unsigned int i) const
	{
		if (i >= this->arr_size || i < 0)
			throw std::invalid_argument("INVALID INDEX");
		return ((this->arr[i]));
	}

	int			size(void) const
	{
		return this->arr_size;
	}
private:
	T				*arr;
	unsigned int	arr_size;
};
#endif