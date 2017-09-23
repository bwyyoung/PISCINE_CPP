/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MUTANT_
#define _MUTANT_
#include <iostream>
#include <stack>
#include <list>
#include <iterator>

template <typename T>
class		MutantStack : public std::stack<T>
{
private:
	std::stack<T> m_stack;
	std::list<T> m_list;

public:
	MutantStack<T>(void) {}
	~MutantStack<T>(void) {}

	MutantStack<T>(MutantStack<T> & src)
	{
		*this = src;
	}

	MutantStack &				operator=(MutantStack<T> const & src)
	{
		if (this == &src)
			return *this;
		while (!m_stack.empty())
			m_stack.pop();
		while (!m_list.empty())
			m_list.pop_front();
		m_stack = src.m_stack;
		m_list = src.m_list;
		return (*this);
	}

	void						push(T value)
	{
		m_list.push_front(value);
		m_stack.push(value);
	}

	void						pop(void)
	{
		m_list.pop_front();
		m_stack.pop();
	}

	void						swap(MutantStack<T> &src)
	{
		std::swap(this->m_stack, src.m_stack);
		std::swap(this->m_list, src.m_list);
	}

	bool 						empty() const
	{
		return m_stack.empty();
	}

	T							top(void)
	{
		return m_stack.top();
	}

	T							size(void)
	{
		return m_stack.size();
	}

	typedef std::list<int>::iterator iterator;

	iterator					begin()
	{
		return m_list.begin();
	}
	iterator					end() {
		return m_list.end();
	}

};

#endif