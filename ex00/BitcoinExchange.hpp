/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:58:56 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/17 14:55:36 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <fstream>
# include <exception>

# define DB_FILE	"data.csv"
# define COL_R		"\033[31m"
# define COL_G		"\033[32m"
# define COL_Y		"\033[33m"
# define COL_B		"\033[34m"
# define COL_X		"\033[0m"

class BitcoinExchange
{
	private:
		std::map<std::string, double> _db;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	calculate(const std::string &line) const;
		void	importDatabase();

		class NoDatabaseException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};

		class CorruptedDatabaseException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};

		class NumberTooSmallException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};

		class NumberTooLargeException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};

		class BadInputException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};

		class EarlyDateException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};
};
#endif
