/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:25:38 by hepereir          #+#    #+#             */
/*   Updated: 2025/07/25 14:51:51 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

AForm::AForm() : name("Default"), formsigned(false), gradeRequiredSign(150), gradeRequiredExec(150) 
{
    std::cout << "Default Form created" << std::endl;
}

AForm::AForm(std::string name, int gradeRequiredSign, int gradeRequiredExec)
    : name(name), formsigned(false), gradeRequiredSign(gradeRequiredSign), gradeRequiredExec(gradeRequiredExec) 
{
    if (gradeRequiredSign < 1 || gradeRequiredExec < 1)
        throw GradeTooHighException();
    else if (gradeRequiredSign > 150 || gradeRequiredExec > 150)
        throw GradeTooLowException();
    std::cout << name <<" created" << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name), formsigned(other.formsigned), gradeRequiredSign(other.gradeRequiredSign), gradeRequiredExec(other.gradeRequiredExec) 
{
    std::cout << "Default copy constructed called" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->formsigned = other.formsigned;
    std::cout << "Default copy assignment called" << std::endl;
    return *this;
}

AForm::~AForm()
{
    std::cout << "Destructor called" << std::endl;
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getSigned() const
{
    return (this->formsigned);
}

int AForm::getGradeSign() const
{
    return (this->gradeRequiredSign);
}

int AForm::getGradeExec() const
{
    return (this->gradeRequiredExec);
}

void AForm::beSigned(const Bureaucrat& burecraut)
{
    if (burecraut.getGrade() <= gradeRequiredSign)
        formsigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << "****************************\n" << f.getName() << " form info:\nSigned: " << f.getSigned()
        << "\nGrade to sign: " << f.getGradeSign() << "\nGrade to exec: "
        << f.getGradeExec() << "\n****************************\n" << std::endl;
    return out;
}