/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:58:56 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/19 18:29:05 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// # include <stack>
# include <iostream>
# include <exception>
# include <list>
# include <deque>
# include <climits>
# include <vector>

# define COL_R		"\033[31m"
# define COL_G		"\033[32m"
# define COL_Y		"\033[33m"
# define COL_B		"\033[34m"
# define COL_X		"\033[0m"

void	init_numbers_vector(std::vector<int> *numbers, char **argv);
void	init_numbers_deque(std::deque<int> *numbers, char **argv);
void	print_vector(const std::vector<int> &numbers, const std::string &msg);

// template <typename T>
// void	printContainer(const T &container);
// template <typename T>
// void	printContainerGroups(const T &container, size_t groupSize);

void	merge_insertion_sort_vector
		(std::vector<int> &vector,
		size_t start, size_t end, size_t groupSize);
void	merge_insertion_sort_deque
		(std::deque<int> &deque,
		size_t start, size_t end, size_t groupSize);


class	IncorrectInputException : public std::exception {};

#endif
