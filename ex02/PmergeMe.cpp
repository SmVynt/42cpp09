/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:12:16 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/18 00:11:10 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	calculate(const std::string &line)
{
}

// EXCEPTIONS

const char*	IncorrectInputException::what() const noexcept{
	return "Error: incorrect input.";
}


