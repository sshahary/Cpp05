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
#include "Form.hpp"

int main()
{
    try
	{
        Bureaucrat bob("Bob", 2);
        Form taxForm("TaxForm", 3, 5);
        
        std::cout << bob << std::endl;
        std::cout << taxForm << std::endl;

        bob.signForm(taxForm);
        std::cout << taxForm << std::endl;
        
        Bureaucrat alice("Alice", 4);
        alice.signForm(taxForm);
    }
    catch (const std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
	{
        Form invalidForm("InvalidForm", 0, 150);  // This should throw an exception
    }
    catch (const std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
	{
        Form anotherInvalidForm("AnotherInvalidForm", 150, 151);  // This should throw an exception
    }
    catch (const std::exception &e)
	{
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}