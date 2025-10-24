/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:49:39 by kevwang           #+#    #+#             */
/*   Updated: 2025/10/24 15:49:40 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat();
Bureaucrat::~Bureaucrat();
Bureaucrat::Bureaucrat(const Bureaucrat &copy);
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other);

std::string Bureaucrat::getName() const;
std::string Bureaucrat::getGrade() const;

ostream &operator<<(ostream &out, const Bureaucrat &c);
{
    out << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;;
    return out;
}