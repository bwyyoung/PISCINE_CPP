/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PISCINE_C_SERIALIZER_HPP
#define PISCINE_C_SERIALIZER_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>

struct			Data
{
	std::string	s1;
	int			n;
	std::string	s2;
};

class serializer
{
public:
	static serializer*	getInstance();
	~serializer(void);
	std::string			get_list();
	char*				get_alphanumeric();
	Data*				get_data();
private:
	serializer(void);
	serializer(serializer const & src);
	serializer &		operator=(serializer const & src);
	char			*alphanumeric;
	std::string		list;
	Data *			data;
};


#endif //PISCINE_C_serializer_HPP
