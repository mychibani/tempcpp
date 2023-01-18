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


#ifndef __FORM_HPP__
# define __FORM_HPP__

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int rqrd_sgnd_grd, int rqrd_xct_grd, std::string target);
		Form(const Form &rhs);
		Form &operator=(const Form &rhs);
		~Form();
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
		unsigned int		get_sgnd_grd_rqrd() const;
		unsigned int		get_xct_grd_rqrd() const;
		bool				isSigned() const;
		void				beSigned(Bureaucrat& bureaucrat);
	private:
		const std::string	__name;
		bool				__is_signed;
		const unsigned int	__rqrd_sgn_grd;
		const unsigned int	__rqrd_xct_grd;
		const unsigned int	__trgt;
};

std::ostream& operator<<(std::ostream& stream, const Form &form);

#endif
