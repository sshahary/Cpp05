#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class Intern
{
    private:
        AForm* createShrubberyCreationForm(const std::string& target);
        AForm* createRobotomyRequestForm(const std::string& target);
        AForm* createPresidentialPardonForm(const std::string& target);
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target);
};

#endif
