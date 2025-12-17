/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:12:16 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/17 17:22:00 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	RPN::calculate(const std::string &line)
{
	std::stack<int>	stack;
	std::string		numbers = "0123456789";

	for (size_t i = 0; i < line.length(); ++i)
	{
		if (line[i] == ' ' || line[i] == '\t')
			continue;

		if (numbers.find(line[i]) != std::string::npos)
		{
			stack.push(line[i] - '0');
			continue;
		}

		switch (line[i])
		{
			case '+':
				if (stack.size() < 2)
					throw IncorrectInputException();
				{
					int b = stack.top();
					stack.pop();
					int a = stack.top();
					stack.pop();
					stack.push(a + b);
				}
				break;
			case '-':
				if (stack.size() < 2)
					throw IncorrectInputException();
				{
					int b = stack.top();
					stack.pop();
					int a = stack.top();
					stack.pop();
					stack.push(a - b);
				}
				break;
			case '*':
				if (stack.size() < 2)
					throw IncorrectInputException();
				{
					int b = stack.top();
					stack.pop();
					int a = stack.top();
					stack.pop();
					stack.push(a * b);
				}
				break;
			case '/':
				if (stack.size() < 2)
					throw IncorrectInputException();
				{
					int b = stack.top();
					stack.pop();
					int a = stack.top();
					stack.pop();
					if (b == 0)
						throw IncorrectInputException();
					stack.push(a / b);
				}
				break;
			default:
				throw IncorrectInputException();
		}
	}
	if (stack.size() != 1)
		throw IncorrectInputException();
	return stack.top();
}

// EXCEPTIONS

const char*	RPN::IncorrectInputException::what() const noexcept{
	return "Error: incorrect input.";
}

// CANONICAL FORM

RPN::RPN() {};

RPN::RPN(const RPN &other) { (void)other; };

RPN	&RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
};

RPN::~RPN(){};
