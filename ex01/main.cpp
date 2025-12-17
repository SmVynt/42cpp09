/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:47:57 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/15 15:45:04 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "Span.hpp"

#define VEC_SIZE	30000
#define VEC2_SIZE	100

int main()
{
	srand(time(NULL));
	Span sp(VEC_SIZE);

	std::cout << "Checking empty Span" << std::endl;
	try	{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "...................." << std::endl;

	std::cout << "Adding numbers + 1 extra" << std::endl;
	for (int i = 0; i < VEC_SIZE; i++)
		sp.addNumber(rand() * (rand() % 2 ? 1 : -1));
	std::cout << "Added " << VEC_SIZE << " numbers." << std::endl;
	try	{
		sp.addNumber(42);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "...................." << std::endl;

	std::cout << "Checking Span" << std::endl;
	try	{
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "...................." << std::endl;

	std::cout << "Adding numbers in Range" << std::endl;
	Span sp2(VEC2_SIZE);
	int arr[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
	std::vector<int> vec = {
		-3504, 4080, 2803, -851, -4850, 4424, 913, -1449, 2904, -394, 267, 2097, -474, -3728, 622, 4992, -2397, 215, 2180, 2021, -583, 1860, -712, -3059, 2940, 4298, -2405, -2402, -638, -2339, 1332, 743, 2675, 186, -1696, -1334, 4609, -2313, -1598, 151, -1621, -2763, -633, 810, 3434, -1571, 1358, 3693, 4357, 2429, 163, 4584, -4829, 4076, 65, 426, -4025, 615, -4513, 4694, 1894, 4487, 2234, -2096, 1897, -4505, 861, 1950, 4537, 2619, -4070, -1591, -3343, 1314, 1336, 1088, 2730, 4566, 4760, 647, 1623, -3878, 678, 1034, -2739, -89, -4254, -4191, -1955, -606};
	try{
		sp2.addRange(arr, arr + 10);
		std::cout << "Added 10 numbers." << std::endl;
		sp2.addRange(vec.begin(), vec.end());
		std::cout << "Added " << vec.size() << " numbers." << std::endl;
		std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
		sp2.addRange(arr, arr + 10);
	}
	catch(const std::exception& e)	{
		std::cerr << e.what() << '\n';
	}

	return 0;

	// Span sp = Span(5);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	// return 0;
}
