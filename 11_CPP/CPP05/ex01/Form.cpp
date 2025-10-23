/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:25:38 by hepereir          #+#    #+#             */
/*   Updated: 2025/07/25 13:49:47 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

Form::Form() : name("Default"), formsigned(false), gradeRequiredSign(150), gradeRequiredExec(150) 
{
    std::cout << "Default Form created" << std::endl;
}

Form::Form(std::string name, int gradeRequiredSign, int gradeRequiredExec)
    : name(name), formsigned(false), gradeRequiredSign(gradeRequiredSign), gradeRequiredExec(gradeRequiredExec) 
{
    if (gradeRequiredSign < 1 || gradeRequiredExec < 1)
        throw GradeTooHighException();
    else if (gradeRequiredSign > 150 || gradeRequiredExec > 150)
        throw GradeTooLowException();
    std::cout << name <<" created" << std::endl;
}

Form::Form(const Form &other)
    : name(other.name), formsigned(other.formsigned), gradeRequiredSign(other.gradeRequiredSign), gradeRequiredExec(other.gradeRequiredExec) 
{
    std::cout << "Default copy constructed called" << std::endl;
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
        this->formsigned = other.formsigned;
    std::cout << "Default copy assignment called" << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getSigned() const
{
    return (this->formsigned);
}

int Form::getGradeSign() const
{
    return (this->gradeRequiredSign);
}

int Form::getGradeExec() const
{
    return (this->gradeRequiredExec);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeRequiredSign)
        formsigned = true;
    else
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << "****************************\n" << f.getName() << " form info:\nSigned: " << f.getSigned()
        << "\nGrade to sign: " << f.getGradeSign() << "\nGrade to exec: "
        << f.getGradeExec() << "\n****************************\n" << std::endl;
    return out;
}