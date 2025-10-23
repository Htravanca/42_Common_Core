/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:25:40 by hepereir          #+#    #+#             */
/*   Updated: 2025/07/26 22:44:43 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

// Forward declaration to avoid circular dependency
class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool formsigned;
        const int gradeRequiredSign;
        const int gradeRequiredExec;
    public:
        //ocf
        AForm();
        AForm(std::string name, int gradeRequiredSign, int gradeRequiredExec);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();

        //getters
        std::string getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;

        //setters
        void beSigned(const Bureaucrat& burecraut);

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

        //abstract by adding at least one pure virtual function
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif