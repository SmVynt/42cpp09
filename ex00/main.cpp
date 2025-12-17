/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:47:57 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/17 14:51:52 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << COL_R << "Error: could not open file." << COL_X << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << COL_R << "Error: could not open file." << COL_X << std::endl;
		return 1;
	}

	// Importing a database

	BitcoinExchange	exchange;
	try
	{
		exchange.importDatabase();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	// Reading lines
	std::string 	line;
	while (std::getline(file, line))
	{
		try
		{
			exchange.calculate(line);
		}
		catch (const BitcoinExchange::BadInputException &e)
		{
			std::cerr << COL_R << e.what() << line << COL_X << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << COL_R << e.what() << COL_X << std::endl;
		}
	}

	return 0;
}
