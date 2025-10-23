/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 22:00:12 by hepereir          #+#    #+#             */
/*   Updated: 2025/07/26 22:38:25 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Default Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    std::cout << "Default Intern copy assignemnt called" << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Default Intern destructor called" << std::endl;
}

AForm* createShrubbery(std::string const &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string const &target)
{
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(std::string const &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const &formname, std::string const &target)
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*formCreators[])(std::string const &target) = {
        createShrubbery, createRobotomy, createPresidential};
    
    for (int i = 0; i < 3; ++i)
    {
        if (formname == formNames[i])
        {
            std::cout << "Intern creates " << formname << std::endl;
            return formCreators[i](target);
        }
    }

    std::cerr << "Error: Form name \"" << formname << "\" does not exist." << std::endl;
    return NULL;
}
