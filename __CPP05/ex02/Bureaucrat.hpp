/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchalle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:36:55 by xchalle           #+#    #+#             */
/*   Updated: 2022/03/22 14:43:27 by xchalle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H


#include "Form.hpp" 
#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
	public:

	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(const Bureaucrat &rhs);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &rhs);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("grade higher than 1");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const throw()
		{
			return ("grade lower than 150");
		}
	};

	const std::string&	getName() const;
	unsigned int	getGrade() const;
	void		incrGrade();
	void		decrGrade();
	void		signForm(Form &form);

	protected:
	private:

	const std::string	name;
	unsigned int		grade;
};

std::ostream& operator<<(std::ostream& stream, const Bureaucrat &bureaucrat);

#endif
