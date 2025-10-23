/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:02:31 by hepereir          #+#    #+#             */
/*   Updated: 2025/06/29 14:22:17 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const int SIZE = 4;
    const Animal* animals[SIZE];

    for (int i = 0; i < SIZE; ++i) {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "------ Sounds ------" << std::endl;
    for (int i = 0; i < SIZE; ++i)
        animals[i]->makeSound();

    std::cout << "------ Deleting ------" << std::endl;
    for (int i = 0; i < SIZE; ++i)
        delete animals[i];

    std::cout << "------ Deep copy ------" << std::endl;
    Dog original;
    original.setIdea(0, "Chase the mailman!");
    original.setIdea(1, "Bark at the neighbor.");
    Dog copy = original;

    std::cout << "Original Dog's Ideas:" << std::endl;
    std::cout << "Idea 0: " << original.getIdea(0) << std::endl;
    std::cout << "Idea 1: " << original.getIdea(1) << std::endl;

    std::cout << "Copied Dog's Ideas:" << std::endl;
    std::cout << "Idea 0: " << copy.getIdea(0) << std::endl;
    std::cout << "Idea 1: " << copy.getIdea(1) << std::endl;

    copy.setIdea(0, "Sleep on the couch.");     // Modify copy's brain to ensure deep copy

    std::cout << "After modifying the copy:" << std::endl;
    std::cout << "Original Idea 0: " << original.getIdea(0) << std::endl;
    std::cout << "Copy Idea 0: " << copy.getIdea(0) << std::endl;

    return 0;
}