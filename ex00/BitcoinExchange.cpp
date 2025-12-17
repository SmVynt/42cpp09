/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:12:16 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/17 14:56:32 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	BitcoinExchange::importDatabase()
{
	std::ifstream	file(DB_FILE);
	if (!file.is_open())
		throw NoDatabaseException();

	std::string	line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t	delimiter = line.find(',');
		if (delimiter == std::string::npos)
		{
			throw CorruptedDatabaseException();
			return ;
		}

		std::string	date = line.substr(0, delimiter);
		double		value = std::stod(line.substr(delimiter + 1));
		_db[date] = value;
	}
	file.close();
}

static bool isValidDate(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int	month = std::stoi(date.substr(5, 2));
	int	day = std::stoi(date.substr(8, 2));

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	return true;
}

static void printOutput(const std::string &date, double amount, double result)
{
	std::cout << COL_G << date << COL_X << " => " << amount << " = " << result << std::endl;
}

void	BitcoinExchange::calculate(const std::string &line) const
{
	size_t	delimiter = line.find('|');
	if (delimiter == std::string::npos)
	{
		throw BadInputException();
		return ;
	}

	std::string	date = line.substr(0, delimiter - 1);
	double		amount = std::stod(line.substr(delimiter + 1));

	if (amount < 0)
		throw NumberTooSmallException();
	if (amount > 1000)
		throw NumberTooLargeException();
	if (!isValidDate(date))
		throw BadInputException();

	std::map<std::string, double>::const_iterator it = _db.find(date);
	if (it != _db.end() || it->first != date)
	{
		printOutput(date, amount, it->second * amount);
		return ;
	}
	it = _db.upper_bound(date);
	if (it == _db.begin())
	{
		throw EarlyDateException();
		return ;
	}

	--it;
	double	rate = it->second;
	double	result = rate * amount;
	printOutput(date, amount, it->second * amount);
}

// EXCEPTIONS

const char*	BitcoinExchange::NoDatabaseException::what() const noexcept{
	return "Error: database not loaded.";
}

const char*	BitcoinExchange::CorruptedDatabaseException::what() const noexcept{
	return "Error: database is corrupted.";
}

const char*	BitcoinExchange::NumberTooSmallException::what() const noexcept{
	return "Error: too small a number.";
}

const char*	BitcoinExchange::NumberTooLargeException::what() const noexcept{
	return "Error: too large a number.";
}

const char*	BitcoinExchange::BadInputException::what() const noexcept{
	return "Error: bad input => ";
}

const char*	BitcoinExchange::EarlyDateException::what() const noexcept{
	return "Error: no earlier date in database.";
}

// CANONICAL FORM

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { (void)other; }

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	if (!_db.empty())
		_db.clear();
}
