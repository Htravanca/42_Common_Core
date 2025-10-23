/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 12:36:16 by hepereir          #+#    #+#             */
/*   Updated: 2025/07/25 16:21:39 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL)); // Seed random for RobotomyRequestForm

    std::cout << "===== TEST 1: ShrubberyCreationForm =====\n";
    Bureaucrat lowRank("LowRank", 146);
    ShrubberyCreationForm Pinheiro("Garden");

    lowRank.signForm(Pinheiro);
    lowRank.incrementGrade(); // grade 145
    lowRank.signForm(Pinheiro);
    lowRank.executeForm(Pinheiro);

    while (lowRank.getGrade() > Pinheiro.getGradeExec())
        lowRank.incrementGrade();
    lowRank.executeForm(Pinheiro);

    std::cout << "\n===== TEST 2: RobotomyRequestForm =====\n";
    Bureaucrat midRank("MidRank", 73);
    RobotomyRequestForm roboooo("TargetBot");

    midRank.signForm(roboooo);
    midRank.incrementGrade(); // grade 72
    midRank.signForm(roboooo);
    midRank.executeForm(roboooo);

    while (midRank.getGrade() > roboooo.getGradeExec())
        midRank.incrementGrade();
    for (int i = 0; i < 2; ++i)
        midRank.executeForm(roboooo);

    std::cout << "\n===== TEST 3: PresidentialPardonForm =====\n";
    Bureaucrat president("President", 1);
    PresidentialPardonForm pardonForm("Ford Prefect");

    president.signForm(pardonForm);
    president.executeForm(pardonForm);

    return (0);
}
