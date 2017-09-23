/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byoung-w <byoung-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/08 14:49:06 by byoung-w          #+#    #+#             */
/*   Updated: 2014/09/08 14:49:10 by byoung-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SHRUB_
#define _SHRUB_

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <istream>
#include <fstream>

class						ShrubberyCreationForm : public Form
{
private:
	static const int sign;
	static const int exec;
	ShrubberyCreationForm(void);
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm&		operator=(ShrubberyCreationForm const & rhs);
	~ShrubberyCreationForm();
	void						execute(Bureaucrat const & executor) const;
};

#endif
