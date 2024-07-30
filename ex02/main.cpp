/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshahary <sshahary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 22:28:13 by sshahary          #+#    #+#             */
/*   Updated: 2024/07/27 22:29:25 by sshahary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 2);
        Bureaucrat alice("Alice", 140);

        ShrubberyCreationForm shrubberyForm("home");
        RobotomyRequestForm robotomyForm("Alice");
        PresidentialPardonForm pardonForm("Bob");

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        alice.signForm(shrubberyForm);
        bob.signForm(robotomyForm);
        bob.signForm(pardonForm);

        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

        alice.executeForm(shrubberyForm);
        bob.executeForm(robotomyForm);
        bob.executeForm(pardonForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
