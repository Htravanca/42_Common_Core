/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepereir <hepereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:24:31 by hepereir          #+#    #+#             */
/*   Updated: 2025/05/12 22:15:51 by hepereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string ft_replace(const std::string &line, const std::string &s1, const std::string &s2)
{
    std::size_t found = 0;
    std::size_t pos = 0;
    std::string result;

    while ((found = line.find(s1, pos)) != std::string::npos)
    {
        result += line.substr(pos, found - pos); 
        result += s2;
        pos = found + s1.length();
    }
    result += line.substr(pos, line.length() - pos);
    return (result);
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return (std::cout << "Example: ./sedisforlosers \"filename\" \"s1\" \"s2\"" << std::endl, 1);
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string line;
    
    if (filename.empty())
        return (std::cout << "Error: filename cannot be empty" << std::endl, 1);
    if (s1.empty())
        return (std::cout << "Error: s1 cannot be empty" << std::endl, 1);
    std::ifstream infile(filename.c_str(), std::ifstream::in);
    if (!infile)
        return (std::cout << "Error: could not open input file" << std::endl, 1);
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
        return (std::cout << "Error: could not open output file" << std::endl, 1);
    while (std::getline(infile, line))
    {
        outfile << ft_replace(line, s1, s2) << std::endl;
    }
    return 0;
}
