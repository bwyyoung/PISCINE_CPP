/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

void				Span::addNumber(int num)
{
	if (this->current_N >= this->limit_N)
		throw std::invalid_argument("SPAN FULL");
	this->tree_add_span(&this->span_tree, num);
	this->current_N++;
}

t_span_number		*Span::create_t_span_number(int num)
{
	t_span_number *tree = new t_span_number();
	(tree)->m_span = num;
	return tree;
}

void				Span::tree_add_span(t_span_number **tree, int thenum)
{
	if (*tree == NULL)
		*tree = create_t_span_number(thenum);
	else if (thenum > (*tree)->m_span)
	{
		if ((*tree)->right != NULL)
			this->tree_add_span(&(*tree)->right, thenum);
		else
			(*tree)->right = create_t_span_number(thenum);
	}
	else
	{
		if ((*tree)->left != NULL)
			this->tree_add_span(&(*tree)->left, thenum);
		else
			(*tree)->left = create_t_span_number(thenum);
	}
}

void				Span::destroy_tree(t_span_number **tree)
{
	if (*tree == NULL)
		return;
	this->destroy_tree(&(*tree)->left);
	this->destroy_tree(&(*tree)->right);
	delete *tree;
}

int					Span::tree_find_shortest(t_span_number **tree, int parent)
{
	if (*tree == NULL)
		throw std::invalid_argument("tree_find_shortest NULL");
	bool	check_left = false;
	bool 	check_right = false;
	int		left_shortest = 0;
	int		right_shortest = 0;
	int		my_left_shortest = 0;
	int		my_right_shortest = 0;

	if ((*tree)->left != NULL)
	{
		my_left_shortest = std::abs((*tree)->m_span
									- (*tree)->left->m_span);
		left_shortest = tree_find_shortest(&(*tree)->left, my_left_shortest);
		check_left = true;
	}
	if ((*tree)->right != NULL)
	{
		my_right_shortest = std::abs((*tree)->m_span
									 - (*tree)->right->m_span);
		right_shortest = tree_find_shortest(&(*tree)->right, my_right_shortest);
		check_right = true;
	}
	if (!check_left && !check_right) //we are at the leaf of the tree
		return (parent + 1);
	else if (!check_left)
		return ::min(right_shortest, my_right_shortest);
	else if (!check_right)
		return ::min(left_shortest, my_left_shortest);
	left_shortest = ::min(left_shortest, my_left_shortest);
	right_shortest = ::min(right_shortest, my_right_shortest);
	return ::min(left_shortest, right_shortest);
}

int					Span::tree_find_longest(t_span_number **tree)
{
	if (*tree == NULL)
		throw std::invalid_argument("tree_find_longest NULL");

	t_span_number *cur_left = *tree;
	t_span_number *cur_right = *tree;
	while (cur_left->left != NULL)
		cur_left = cur_left->left;
	while (cur_right->right != NULL)
		cur_right = cur_right->right;
	return std::abs(cur_right->m_span - cur_left->m_span);
}

int					Span::shortestSpan(void)
{
	if (this->current_N <= 1)
		throw std::exception();
	this->shortest_distance = this->tree_find_shortest(&this->span_tree, -1);
	return this->shortest_distance;
}

int					Span::longestSpan(void)
{
	if (this->current_N <= 1)
		throw std::exception();
	this->longest_distance = this->tree_find_longest(&this->span_tree);
	return this->longest_distance;
}


void				Span::add_container(std::vector<int>& container)
{
	if (container.empty())
		throw std::invalid_argument("Container Empty");

	for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
		addNumber(*it);
};

Span::Span(unsigned int N)
{
	this->limit_N = N;
	this->current_N = 0;
	this->span_tree = NULL;
}

Span::Span(void)
{
	this->current_N = 0;
	this->limit_N = 0;
	this->span_tree = NULL;
}

Span::~Span()
{
	this->destroy_tree(&this->span_tree);
}

Span & Span::operator=(Span const & rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::Span(unsigned int begin, unsigned int end)
{
	int		first = 0;
	int		second = 5;
	int		next;
	if (static_cast<int>(begin) < 0 || static_cast<int>(end) < 0)
		throw std::invalid_argument("Numbers input not valid");
	if (end <= begin)
		throw std::invalid_argument("Numbers input not valid");
	this->current_N = 0;
	this->limit_N = end;
	this->span_tree = NULL;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	//fibonacci sequence of numbers
	for (unsigned int i = begin; i < end; i++)
	{
		if ( i == 0)
			next = i;
		else
		{
			next = first + second;
			first = second;
			second = next;
		}
		this->addNumber(next);
	}
}
