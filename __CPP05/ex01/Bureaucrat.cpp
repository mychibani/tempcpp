/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:54:59 by xchalle           #+#    #+#             */
/*   Updated: 2022/03/27 15:20:33 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat() : name("Christian"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( std::string name, unsigned int new_grade) : name(name)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	if (new_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (new_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = new_grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : name(rhs.name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = rhs;
	return ;
}

Bureaucrat	&Bureaucrat::operator=( const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat copy assignement operator called" << std::endl;
	grade = rhs.grade;
	return  *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

const std::string&	Bureaucrat::getName() const
{
	return (name);
}

unsigned int Bureaucrat::getGrade() const
{
	return (grade);
}


void	Bureaucrat::incrGrade()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void	Bureaucrat::decrGrade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl; 
	}
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (stream);
}
