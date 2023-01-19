/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychibani <ychibani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:42:53 by ychibani          #+#    #+#             */
/*   Updated: 2023/01/18 22:06:57 by ychibani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain (void)
{
	std::cout << "[Brain default constructor]" << std::endl;
}

Brain::Brain(const Brain &cpy)
{
	std::cout << "[Brain copy constructor]" << std::endl;
	for (int i = 0; i < __MAX_IDEAS; i++)
		this->Ideas[i] = cpy.Ideas[i];
	*this = cpy;
}

Brain Brain::operator=(const Brain &to_assign)
{
	std::cout << "[Brain assignation operator called]" << std::endl;
	if (this == &to_assign)	
		return (*this);
	for (int i = 0; i < __MAX_IDEAS; i++)
		this->Ideas[i] = to_assign.Ideas[i];
	return (*this);
}

std::string Brain::get_idea(int index)
{
	if (index >= __MAX_IDEAS || index < 0)
	{
		std::cerr << "can't get this idea" << std::endl;
		return ("this idea doesn't exist");
	}
	return (this->Ideas[index]);
}

void Brain::set_idea(int index, std::string new_idea)
{
	if (index >= __MAX_IDEAS || index < 0)
	{
		std::cerr << "can't add this idea" << std::endl;
		return ;
	}
	this->Ideas[index] = new_idea;
}

Brain::~Brain (void)
{
	std::cout << "[Brain destructor called]" << std::endl;
}