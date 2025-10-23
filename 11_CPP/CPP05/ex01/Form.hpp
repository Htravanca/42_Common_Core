/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:25:40 by hepereir          #+#    #+#             */
/*   Updated: 2025/07/25 13:44:32 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

// Forward declaration to avoid circular dependency
class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool formsigned;
        const int gradeRequiredSign;
        const int gradeRequiredExec;
    public:
        //ocf
        Form();
        Form(std::string name, int gradeRequiredSign, int gradeRequiredExec);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();

        //getters
        std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;

        //setters
        void beSigned(const Bureaucrat& bureaucrat);

        //exeptions
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif