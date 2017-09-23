/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PISCINE_C_BASE_HPP
#define PISCINE_C_BASE_HPP

#include <iostream>
#include <stdlib.h>

class Base
{
public:
	virtual ~Base(void) {};
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

#endif
