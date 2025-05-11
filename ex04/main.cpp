/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelitoris <mikelitoris@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 09:51:23 by mikelitoris       #+#    #+#             */
/*   Updated: 2025/05/10 18:21:17 by mikelitoris      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char **argv)
{
	std::string	str; // String to store the modified content 
	std::ifstream	infile; // Input file stream to read from the file
	std::ofstream	outfile; // Output file stream to write to the file

	
	// Check if the correct number of arguments is passed
	if (argc != 4)
	{
		std::cout << "usage: replace <file> old_word new_word" << std::endl;
		return (1);
	}
	// Check if the old_word is empty
	if (!argv[2] || argv[2][0] == '\0')
	{
		std::cout << "Error: old_word cannot be empty" << std::endl;
		return (1);
	}
	
	std::string filename = argv[1];
	std::string old_word = argv[2];
	std::string new_word = argv[3];

	// Open the input file
	infile.open(filename.c_str());
	if (infile.fail())
	{
		std::cout << "Error: file not found" << std::endl;
		return (1);
	}

	// Create and open the output file
	outfile.open((filename + ".replace").c_str());
	if (outfile.fail())
	{
		std::cout << "Error: could not create the output file" << std::endl;
		return (1);
	}

	// Read the input file into a string
	std::string	content;
	std::string	line;
	
	while (std::getline(infile, line))
	{
		content += line;
		if (!infile.eof())
			content += '\n';
	}
	infile.close();
	
	// Build the new string with the replaced word
	std::string	result;
	std::size_t	pos = 0;
	std::size_t	found = 0;

	while ((found = content.find(old_word, pos)) != std::string::npos)
	{
		// Append substring before the occurence
		result.append(content, pos, found - pos);
		// Append the new word
		result.append(new_word);
		// Update the position to after the replaced substring
		pos = found + old_word.length();
	}
	
	// Append the rest of the string
	result.append(content, pos, content.length() - pos);

	// Write the new string to the output file
	outfile << result;
	outfile.close();

	return (0);
}