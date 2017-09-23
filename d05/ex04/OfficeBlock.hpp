/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OFFICEBLOCK__
# define __OFFICEBLOCK__

#include "Intern.hpp"
#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

class OfficeBlock
{
private:
	Bureaucrat *		signer;
	Bureaucrat *		executor;
	Intern *			intern;
	Form *				f;

	OfficeBlock & operator=(OfficeBlock const & rhs);
	OfficeBlock(OfficeBlock const & src);
public:
	OfficeBlock(void);
	~OfficeBlock(void);

	void doBureaucracy(std::string, std::string);
	void setIntern(Intern & intern);
	void setSigner(Bureaucrat & signer);
	void setExecutor(Bureaucrat & executor);
	class StaffNotFoundException : public std::exception
	{
	public:
		StaffNotFoundException(void);
		StaffNotFoundException(StaffNotFoundException const & src);
		virtual ~StaffNotFoundException(void) throw();
		StaffNotFoundException & operator=(StaffNotFoundException const & rhs);
		virtual const char * what() const throw();
	};
};

#endif
