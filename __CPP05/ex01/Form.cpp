/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:22:32 by xchalle           #+#    #+#             */
/*   Updated: 2022/03/28 11:27:22 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

Form::Form() : name("default name") , s_grade(1) , e_grade(1)

{
	std::cout << "Form default constructor called" << std::endl;
	this->_signed = false;
	return ;
}

Form::Form( std::string name, unsigned int new_s_grade, unsigned int new_e_grade) : name(name) , s_grade(new_s_grade) , e_grade(new_e_grade)
{
	std::cout << "Form constructor called" << std::endl;
	if (new_s_grade < 1 || new_e_grade < 1)
		throw Form::GradeTooHighException();
	if (new_s_grade > 150 || new_e_grade > 150)
		throw Form::GradeTooLowException();
	else
		this->_signed = false;
	return ;
}

Form::Form(const Form &rhs) : name(rhs.name), s_grade(rhs.s_grade) , e_grade(rhs.e_grade) 
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = rhs;
	return ;
}

Form	&Form::operator=( const Form &rhs)
{
	std::cout << "Form copy assignement operator called" << std::endl;
	_signed = rhs._signed;
	return  *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
	return ;
}

const std::string&	Form::getName() const
{
	return (name);
}

unsigned int Form::getGrade_s() const
{
	return (s_grade);
}

unsigned int Form::getGrade_e() const
{
	return (e_grade);
}

bool	Form::isSigned() const
{
	return (_signed);
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{	
	if (isSigned() == true)
		throw std::invalid_argument("form signed yet");
	if ((bureaucrat.getGrade()) <= s_grade)
		_signed = true;
	else
		throw Form::GradeTooHighException();
}

std::ostream&	operator<<(std::ostream& stream, const Form &form)
{
	stream << form.getName() << ", form grade for execute : " << form.getGrade_e() << " grade for signed : " << form.getGrade_e() << " signed status " << form.isSigned();
	return (stream);
}
