/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:49:42 by kevwang           #+#    #+#             */
/*   Updated: 2025/10/24 15:49:44 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &other);

	std::string getName() const;
	std::string getGrade() const;


};

ostream &operator<<(ostream &out, const Bureaucrat &c);
{
    out << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;;
    return out;
}