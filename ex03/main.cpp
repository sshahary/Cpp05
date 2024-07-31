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

// main.cpp
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 1);
        Intern someRandomIntern;
        
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            bob.signForm(*rrf);
            bob.executeForm(*rrf);
            delete rrf;
        }

        AForm* scf;
        scf = someRandomIntern.makeForm("shrubbery creation", "Home");
        if (scf)
        {
            bob.signForm(*scf);
            bob.executeForm(*scf);
            delete scf;
        }

        AForm* ppf;
        ppf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        if (ppf)
        {
            bob.signForm(*ppf);
            bob.executeForm(*ppf);
            delete ppf;
        }

        AForm* nonExistentForm;
        nonExistentForm = someRandomIntern.makeForm("nonexistent form", "Nobody");
        if (nonExistentForm)
        {
            delete nonExistentForm;
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
