/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND
#define EASYFIND

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <list>
#include <deque>
#include <stack>
#include <queue>



//http://stackoverflow.com/questions/5135206/an-std-container-inside-a-template-method
/**
 * For Vector and List
 * @tparam A Container Class (Vector)
 * @tparam B DataType(int)
 * @param container (the container that we are using)
 * @param param (the integer we are searching for)
 */
template<template<class T, class All = std::allocator<T> > class A, class B>
void		easyfind(A<B>& container, int param)
{
	if (container.empty())
		throw std::invalid_argument("Container Empty");
	typename A<B>::iterator it;
	it = std::find(container.begin(), container.end(), param);
	if (it == container.end())
		throw std::invalid_argument("Value Not Found");
	else
		std::cout << "Found Value "<< param
		<<" at index "<< std::distance(container.begin(), it) << std::endl;
};

template <class T, class S, class C>
S& PQ_Container(std::priority_queue<T, S, C>& q) {
	struct HackedQueue : private std::priority_queue<T, S, C>
	{
		/**
		 * http://stackoverflow.com/questions/1400856/i-cant-understand-this-line-dereferencing-an-address-of-private-member-variab
		 * HackedQueue::c, which is just the name of a member variable.
		 * Then you take &HackedQueue::c, which is a pointer to that member
		 * variable. Next you take q, which is just an object reference.
		 * Then you use the "bind pointer to member by reference" operator .*
		 * to bind the member variable referred to by the member-variable
		 * pointer using q as the this.
		 * As to the private member issue, priority_queue::c is only protected,
		 * not private, so it should come as no surprise that when you derive
		 * from priority_queue, that you can access its protected members.
		 */
		static S& Container(std::priority_queue<T, S, C>& q)
		{
			return q.*&HackedQueue::c;
		}
	};
	return HackedQueue::Container(q);
}


/**
 * For Priority_Queue
 * @tparam A
 * @tparam B
 * @param container
 * @param param
 */
template <template <class T, class cont = std::vector<T>, class Compare = std::less<T> > class A, class B>
void		easyfind(A<B>& container, int param)
{
	typename std::vector<B>::iterator	it;
	std::vector<B>						c = PQ_Container(container);
	it = std::find(c.begin(), c.end(), param);
	if (it == c.end() && (*it != param))
		throw std::invalid_argument("Value Not Found");
	else
		std::cout << "Found Value "<< param
				  <<" at index "<< std::distance(c.begin(), it) << std::endl;
}

template <class Container>
class DQ_Adapter : public Container {
public:
	typedef typename Container::container_type container_type;
	container_type &get_container()
	{
		return this->c;
	}
	/**
	 * http://stackoverflow.com/questions/1185252/is-there-a-way-to-access-the-underlying-container-of-stl-container-adaptors
	 * queue/stack/priority_queue (that is, all of the adapter classes)
	 * all have a protected member c which is the underlying container
	 * (see ISO/IEC 14882:2003 section 23.2.2.4), so if you inherit from
	 * any of these, you can access it directly.
	 *
	 * the typical wisdom is to not inherit from STL containers due to
	 * non-virtual dtors, but this case is an exception. The goal is not to
	 * overload functionality, but to make minor extensions to the interface of
	 * the adapter. Here is an example of adding the ability to access
	 * the underlying container.
	 */
};
/**
 * For Stack and Queue
 * @tparam A
 * @tparam B
 * @param container
 * @param param
 */
template <template <class T, class All = std::deque<T> > class A, class B>
void		easyfind(A<B>& container, int param)
{
	typedef A<B> C;
	typedef DQ_Adapter<C> Container;
	typedef typename Container::container_type container_type;
	typename Container::container_type::iterator it;
	if (container.empty())
		throw std::invalid_argument("Container Empty");
	Container *adapter = reinterpret_cast<Container *>(&container);
	container_type c = adapter->get_container();

	it = std::find(c.begin(), c.end(), param);
	if (it == c.end() && (*it != param))
		throw std::invalid_argument("Value Not Found");
	else
		std::cout << "Found Value "<< param
				  <<" at index "<< std::distance(c.begin(), it) << std::endl;
};



#endif