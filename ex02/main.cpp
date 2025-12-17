/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:47:57 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/16 01:53:03 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	// return 0;

	std::cout << "------------------" << std::endl;

	std::list<int> mslist;
	mslist.push_back(5);
	mslist.push_back(17);
	std::cout << mslist.back() << std::endl;
	mslist.pop_back();
	std::cout << mslist.size() << std::endl;
	mslist.push_back(3);
	mslist.push_back(5);
	mslist.push_back(737);
	//[...]
	mslist.push_back(0);
	std::list<int>::iterator it1 = mslist.begin();
	std::list<int>::iterator ite1 = mslist.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
	std::cout << *it1 << std::endl;
	++it1;
	}
	std::list<int> s1(mslist);
	return 0;
}
