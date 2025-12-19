/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:47:57 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/19 18:17:25 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << COL_R << "Error: not enough arguments." << COL_X << std::endl;
		return 1;
	}

	std::vector<int>	numbers;

	try
	{
		init_numbers(&numbers, argv);
		print_vector(numbers, "Before:");
	}
	catch(const IncorrectInputException &e)
	{
		std::cerr << COL_R << "Error: incorrect input." << COL_X << '\n';
		return 1;
	}

	//APPROACH WITH LIST

	std::list<std::pair<int, int>>	pairsList;
	std::list<int>					mainLineList;

	try
	{
		// init_pairs_list(&pairsList, numbers);
		merge_insertion_sort_vector(numbers, 0, numbers.size(), 1);
		print_vector(numbers, "After:");
	}
	catch(const std::exception &e)
	{
		std::cerr << COL_R << "Error: exception occurred during sorting with list." << COL_X << '\n';
		return 1;
	}

	//APPROACH WITH DEQUE

	return 0;
}
