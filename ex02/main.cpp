/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:47:57 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/19 18:52:31 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << COL_R << "Error: not enough arguments." << COL_X << std::endl;
		return 1;
	}

	std::vector<int>	numbersVec;
	std::deque<int>		numbersDeq;


	try
	{
		init_numbers_vector(&numbersVec, argv);
		init_numbers_deque(&numbersDeq, argv);
		print_vector(numbersVec, "Before:");
	}
	catch(const IncorrectInputException &e)
	{
		std::cerr << COL_R << "Error: incorrect input." << COL_X << '\n';
		return 1;
	}

	//APPROACH WITH VECTOR
	try
	{
		clock_t startTime = clock();
		merge_insertion_sort_vector(numbersVec, 0, numbersVec.size(), 1);
		clock_t endTime = clock();
		double timeVec = static_cast<double>(endTime - startTime) / 1000;

		print_vector(numbersVec, "After:");
		std::cout << COL_Y << "Time to process a range of " << numbersVec.size() \
		<< " elements with std::vector : " << COL_X \
		<< std::fixed << std::setprecision(5) << timeVec \
		<< " ms" << std::endl;

	}
	catch(const std::exception &e)
	{
		std::cerr << COL_R << "Error: exception occurred during sorting with vector." << COL_X << '\n';
		return 1;
	}

	//APPROACH WITH DEQUE
	try
	{
		clock_t startTime = clock();
		merge_insertion_sort_deque(numbersDeq, 0, numbersDeq.size(), 1);
		clock_t endTime = clock();
		double timeDeq = static_cast<double>(endTime - startTime) / 1000;

		std::cout << COL_Y << "Time to process a range of " << numbersDeq.size() \
		<< " elements with std::deque : " << COL_X \
		<< std::fixed << std::setprecision(5) << timeDeq \
		<< " ms" << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << COL_R << "Error: exception occurred during sorting with deque." << COL_X << '\n';
		return 1;
	}

	return 0;
}
