/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:17:31 by sshahary          #+#    #+#             */
/*   Updated: 2024/07/27 22:27:55 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}


void Bureaucrat::signForm(AForm& form)
{
    try
	{
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
	{
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return out;
}
