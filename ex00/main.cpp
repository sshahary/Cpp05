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

int main()
{
	try
	{
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;
		
		bob.incrementGrade();
		std::cout << bob << std::endl;

		bob.incrementGrade();  // This should throw an exception
		std::cout << bob << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat alice("Alice", 149);
		std::cout << alice << std::endl;
		
		alice.decrementGrade();
		std::cout << alice << std::endl;

		alice.decrementGrade();  // This should throw an exception
		std::cout << alice << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat invalid("Invalid", 0);  // This should throw an exception
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat invalid("Invalid", 151);  // This should throw an exception
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}