/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK__
# define __PHONEBOOK__

# include <iostream>
# include <string>
# include <locale>
# include <iomanip>

# define SEARCH "SEARCH"
# define ADD "ADD"
# define EXIT "EXIT"
# define RECORD phonebook::t_record
# define NUM_PARAM 11
# define NUM_RECORDS 8

class		phonebook
{
	public:
		phonebook();
		~phonebook();
		void		start_input(void);
		void		test_record_add();
	private:
		class	t_record
		{
			public:
				int				i;
				t_record(): i(0){}
				std::string		data[NUM_PARAM];
		};
		t_record	m_records[NUM_RECORDS];
		size_t		cur_records_size;
		size_t		record_inc;
		void		record_add(void);
		void		record_search(void);
		int			get_record_index(void);
		void		print_record_basic(std::string therecord[], int index);
		static const std::string record_strings[];
		void		print_record_detailed(int index);
};

#endif