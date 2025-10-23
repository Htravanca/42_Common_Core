/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:14:55 by hepereir          #+#    #+#             */
/*   Updated: 2025/07/25 15:59:47 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    std::cout << "Default RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << target << " RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm("RobotomyRequestForm", 72, 45), target(other.target)
{
    std::cout << "copy RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        target = other.target;
    std::cout << "copy RobotomyRequestForm assignment called" << std::endl;
    return *this;
} 

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Default RobotomyRequestForm desctuctor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (this->getSigned() == false)
        throw std::runtime_error("Form is not signed.");

    if (executor.getGrade() > this->getGradeExec())
        throw std::runtime_error("Bureaucrat's grade too low to execute the form.");
    
    std::cout << "🔧 Drilling noises... VRRRRRR!!" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "." << std::endl;
}