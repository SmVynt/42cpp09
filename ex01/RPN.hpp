/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:58:56 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/17 17:18:54 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <exception>

# define COL_R		"\033[31m"
# define COL_G		"\033[32m"
# define COL_Y		"\033[33m"
# define COL_B		"\033[34m"
# define COL_X		"\033[0m"

class RPN
{
	private:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

	public:
		static int	calculate(const std::string &line);

		class IncorrectInputException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};
};

#endif
