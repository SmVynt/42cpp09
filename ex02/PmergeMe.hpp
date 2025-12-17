/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:58:56 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/18 00:10:35 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// # include <stack>
# include <iostream>
# include <exception>

# define COL_R		"\033[31m"
# define COL_G		"\033[32m"
# define COL_Y		"\033[33m"
# define COL_B		"\033[34m"
# define COL_X		"\033[0m"

class IncorrectInputException : public std::exception {
			public:
				virtual const char* what() const noexcept;
		};



#endif
