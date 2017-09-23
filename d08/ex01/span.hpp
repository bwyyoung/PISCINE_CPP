/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/20 16:27:21 by byoung-w          #+#    #+#             */
/*   Updated: 2015/06/21 14:28:24 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SPAN_HPP_
#define _SPAN_HPP_
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <list>
#include <deque>

template <typename T>
T		max(T &a, T &b)
{
	if (a < b)
		return b;
	if (a == b)
		return b;
	return a;
}

template <typename T>
T		min(T &a, T &b)
{
	if (a < b)
		return a;
	if (a == b)
		return b;
	return b;
}

/**
 * Binary trees sorting O(log n)/O(n) are faster than using the std::sort O(n log n).
 *
 * Sorting using std::sort becomes more expensive as the number of items grow larger,
 * whereas the Binary tree already sorts the items inserted on the fly.
 *
 * Therefore, in this case, it is better to implement Span with binary tree.
 * However, we did use std::vector for easy insertion of integers
 * via the add_container function, thereby meeting subject requirements.
 *
 * http://www.cs.northwestern.edu/~riesbeck/programming/c++/stl-summary.html#vector
 * http://bigocheatsheet.com/
 * http://stackoverflow.com/questions/4484900/what-is-the-time-complexity-of-stdsort-in-the-c-standard-library
 * http://stackoverflow.com/questions/205945/why-does-the-c-stl-not-provide-any-tree-containers
 */
typedef struct				s_span_number
{
	struct s_span_number	*left;
	struct s_span_number	*right;
	int						m_span;
	s_span_number():left(NULL),right(NULL),m_span(0) {}
}							t_span_number;

class Span
{
private:
	t_span_number		*span_tree;
	t_span_number		*create_t_span_number(int num);
	void				tree_add_span(t_span_number **tree, int thenum);
	int					tree_find_shortest(t_span_number **tree, int parent);
	int					tree_find_longest(t_span_number **tree);
	void				destroy_tree(t_span_number **tree);
	int					shortest_distance;
	int					longest_distance;
	unsigned int		current_N;
	unsigned int		limit_N;

	Span &				operator=(Span const & src);
public:
	Span(void);
	Span(Span const & src);
	Span(unsigned int N);
	Span(unsigned int begin, unsigned int end);
	~Span();
	void				add_container(std::vector<int>& container);
	void				addNumber(int num);
	int					shortestSpan(void);
	int					longestSpan(void);
};

#endif