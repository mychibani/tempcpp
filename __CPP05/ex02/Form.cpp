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

Form::Form() : __name("default name") , __rqrd_sgn_grd(1) , __rqrd_xct_grd(1), __is_signed(false)

{
	std::cout << "[Form default constructor called]" << std::endl;
}

Form::Form( std::string name, int min_sgn_grd, int min_xct_grd, std::string trgt) : __name(name), __rqrd_sgn_grd(min_sgn_grd), __rqrd_xct_grd(min_xct_grd), __trgt(trgt), __is_signed(false)
{
	std::cout << "[Form complete constructor called]" << std::endl;
	if (min_sgn_grd < 1 || min_xct_grd < 1)
		throw Form::GradeTooHighException();
	if (min_sgn_grd > 150 || min_xct_grd > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &rhs)
{
	std::cout << "[Form copy constructor called]" << std::endl;
	*this = rhs;
}

Form	&Form::operator=( const Form &rhs)
{
	std::cout << "[Form assignement operator called]" << std::endl;
	__is_signed = rhs.__is_signed;
	return *this;
}

Form::~Form()
{
	std::cout << "[Form destructor called]" << std::endl;
	return ;
}

const std::string&	Form::getName() 			const {	return (__name)			;}
unsigned int		Form::get_sgnd_grd_rqrd() 	const {	return (__rqrd_sgn_grd)	;}
unsigned int 		Form::get_xct_grd_rqrd() 	const {	return (__rqrd_xct_grd)	;}
bool				Form::isSigned() 			const {	return (__is_signed)	;}

void				Form::beSigned(Bureaucrat& bureaucrat)
{	
	if (isSigned())
		throw std::invalid_argument("Form already signed");
	if ((bureaucrat.getGrade()) <= __rqrd_sgn_grd)
		__is_signed = true;
	else
		throw Form::GradeTooHighException();
}

std::ostream&	operator<<(std::ostream& stream, const Form &form)
{
	stream << form.getName() << ", form grade for execute : " << form.getGrade_e() << " grade for signed : " << form.getGrade_e() << " signed status " << form.isSigned();
	return (stream);
}
