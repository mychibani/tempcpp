/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:14:55 by xchalle           #+#    #+#             */
/*   Updated: 2022/03/28 11:27:39 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	public:

	Form();
	Form( std::string name, unsigned int new_s_grade, unsigned int new_e_grade);
	Form(const Form &rhs);
	~Form();
	Form &operator=(const Form &rhs);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("form grade too high for this");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("form grade too low for this");
		}
	};

	const std::string&	getName() const;
	unsigned int	getGrade_s() const;
	unsigned int	getGrade_e() const;
	bool	isSigned() const;
	void	beSigned(Bureaucrat& bureaucrat);

	protected:
	private:

	const std::string	name;
	bool			_signed;
	const unsigned int	s_grade;
	const unsigned int	e_grade;
};

std::ostream& operator<<(std::ostream& stream, const Form &form);

#endif
