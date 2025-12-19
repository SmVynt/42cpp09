/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:12:16 by psmolin           #+#    #+#             */
/*   Updated: 2025/12/19 18:35:16 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	init_numbers_vector(std::vector<int> *numbers, char **argv)
{
	long		number;
	std::string	line;

	for (int i = 1; argv[i]; i++)
	{
		line = argv[i];
		if (line.size() > 10)
			throw IncorrectInputException();
		try
		{
			number = std::stol(line);
		}
		catch(const std::exception& e)
		{
			throw IncorrectInputException();
		}
		if (number < 0 || number > INT_MAX)
			throw IncorrectInputException();
		numbers->push_back(static_cast<int>(number));
	}
}

void	init_numbers_deque(std::deque<int> *numbers, char **argv)
{
	long		number;
	std::string	line;

	for (int i = 1; argv[i]; i++)
	{
		line = argv[i];
		if (line.size() > 10)
			throw IncorrectInputException();
		try
		{
			number = std::stol(line);
		}
		catch(const std::exception& e)
		{
			throw IncorrectInputException();
		}
		if (number < 0 || number > INT_MAX)
			throw IncorrectInputException();
		numbers->push_back(static_cast<int>(number));
	}
}

void	print_vector(const std::vector<int> &numbers, const std::string &msg)
{
	std::cout << COL_Y << msg << COL_X;
	for (size_t i = 0; i < numbers.size(); i++)
	{
		std::cout << " " << numbers[i];
	}
	std::cout << std::endl;
}

/**
 * Spaws two groups of elements in a container.
 */
template <typename T>
void	swapGroups(T &container, size_t p_1, size_t p_2, size_t groupSize)
{
	for (size_t i = 0; i < groupSize; i++)
	{
		if (p_1 + i < container.size() && p_2 + i < container.size())
			std::swap(container[p_1 + i], container[p_2 + i]);
		else
			break;
	}
}

/**
 * Get group head value.
 */
template <typename T>
int getGroupHeadValue(const T &container, size_t p, size_t groupSize)
{
	if (p + groupSize <= container.size())
		return container[p + groupSize - 1];
	else
		return -1;
}

/**
 * Push_back a group of elements to a container.
 */
template <typename T>
void	pushBackGroup(T &inContainer, T &outContainer, size_t p, size_t groupSize)
{
	for (size_t i = 0; i < groupSize; i++)
	{
		if (p + i < inContainer.size())
			outContainer.push_back(inContainer[p + i]);
		else
			break;
	}
}

/**
 * Insert a group of elements into a container at position.
 */
template <typename T>
void insertGroup(T &outContainer, const T &inContainer,
	size_t outP, size_t inP, size_t groupSize)
{
	typename T::const_iterator	it_start = inContainer.begin() + inP;
	typename T::const_iterator	it_end = it_start + groupSize;

	if (it_end > inContainer.end())
		it_end = inContainer.end();

	outContainer.insert(outContainer.begin() + outP,
		it_start, it_end);
};


template <typename T>
void	printContainer(const T &container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	printContainerGroups(const T &container, size_t groupSize)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if ((it - container.begin()) % groupSize == 0 && it != container.begin())
			std::cout << "| ";
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/**
 * Binary insertion of Group into main line.
 */
template <typename T>
void	binaryInsertGroup(T &mainLine, const T &pending, size_t p,
		size_t groupsToSearch, size_t groupSize)
{
	size_t	left = 0;
	size_t	right = groupsToSearch;
	size_t	mid;
	size_t	insertPos;
	int		insertValue = getGroupHeadValue(pending, p, groupSize);

	if (groupsToSearch * groupSize > mainLine.size())
		right = mainLine.size() / groupSize;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (getGroupHeadValue(mainLine, mid * groupSize, groupSize) <
			insertValue)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	insertPos = left * groupSize;
	insertGroup(mainLine, pending, insertPos, p, groupSize);
}


// VECTOR APPROACH

void	merge_insertion_sort_vector(std::vector<int> &vector,
		size_t start, size_t end, size_t groupSize)
{
	size_t	numElements;
	size_t	numGroups;
	size_t	numPairs;
	size_t	newEnd;
	bool	hasStrayElement;

	numElements = end - start;
	numGroups = numElements / groupSize;
	numPairs = numGroups / 2;
	if (numGroups <= 1)
		return ;
	if (numGroups == 2)
	{
		if (getGroupHeadValue(vector, start, groupSize) >
			getGroupHeadValue(vector, start + groupSize, groupSize))
		{
			swapGroups(vector, start, start + groupSize, groupSize);
		}
		return ;
	}

	hasStrayElement = (numGroups % 2 == 1);
	newEnd = start + (numPairs * 2) * groupSize;

	//swap groups in pairs
	for (size_t i = start; i < newEnd; i += groupSize * 2)
	{
		size_t p_1 = i;
		size_t p_2 = i + groupSize;
		if (getGroupHeadValue(vector, p_1, groupSize) >
			getGroupHeadValue(vector, p_2, groupSize))
		{
			swapGroups(vector, p_1, p_2, groupSize);
		}
	}

	//recursive call with doubled group size
	// [.][.][.][.] -> [. .][. .] -> [. . . .]
	merge_insertion_sort_vector(vector, start, newEnd, groupSize * 2);

	// now our groups are pre-sorted, we need to merge them

	//builds main chain and pending list
	std::vector<int>	mainLine;
	std::vector<int>	pendingVec;

	//push first two groups to main line since they are already sorted
	pushBackGroup(vector, mainLine, start, groupSize);
	pushBackGroup(vector, mainLine, start + groupSize, groupSize);

	for (size_t i = start + groupSize * 2; i < newEnd; i += groupSize * 2)
	{
		pushBackGroup(vector, pendingVec, i, groupSize);
		pushBackGroup(vector, mainLine, i + groupSize, groupSize);
	}

	if (hasStrayElement)
		pushBackGroup(vector, pendingVec, newEnd, groupSize);

	//insert pending elements to main line using binary search to find correct position using Jacobsthal numbers

	static const size_t jacobsthal[] = {
	1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731,
	5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051,
	1398101, 2796203, 5592405, 11184811, 22369621, 44739243,
	89478485, 178956971, 357913941, 715827883, 1431655765};

	size_t pendIndex = 0;
	size_t finalPendIndex = 0;
	size_t jacobIndex = 0;
	size_t groupsInserted = 0;
	size_t numPending = pendingVec.size() / groupSize;

	while (groupsInserted < numPending)
	{
		jacobIndex++;
		pendIndex = jacobsthal[jacobIndex] - 1;
		if (pendIndex >= numPending)
			pendIndex = numPending - 1;

		while (finalPendIndex <= pendIndex && groupsInserted < numPending)
		{
			size_t searchLimit = pendIndex + 2 + groupsInserted;

			binaryInsertGroup(mainLine, pendingVec,
				pendIndex * groupSize, searchLimit,
				groupSize);
			groupsInserted++;
			if (pendIndex == 0)
				break;
			pendIndex--;
		}
		finalPendIndex = jacobsthal[jacobIndex];
	}

	//update original vector
	for (size_t i = 0; i < mainLine.size(); i++)
		vector[start + i] = mainLine[i];

}

// DEQUE APPROACH

void	merge_insertion_sort_deque(std::deque<int> &deque,
		size_t start, size_t end, size_t groupSize)
{
	size_t	numElements;
	size_t	numGroups;
	size_t	numPairs;
	size_t	newEnd;
	bool	hasStrayElement;

	numElements = end - start;
	numGroups = numElements / groupSize;
	numPairs = numGroups / 2;
	if (numGroups <= 1)
		return ;
	if (numGroups == 2)
	{
		if (getGroupHeadValue(deque, start, groupSize) >
			getGroupHeadValue(deque, start + groupSize, groupSize))
		{
			swapGroups(deque, start, start + groupSize, groupSize);
		}
		return ;
	}

	hasStrayElement = (numGroups % 2 == 1);
	newEnd = start + (numPairs * 2) * groupSize;

	//swap groups in pairs
	for (size_t i = start; i < newEnd; i += groupSize * 2)
	{
		size_t p_1 = i;
		size_t p_2 = i + groupSize;
		if (getGroupHeadValue(deque, p_1, groupSize) >
			getGroupHeadValue(deque, p_2, groupSize))
		{
			swapGroups(deque, p_1, p_2, groupSize);
		}
	}

	//recursive call with doubled group size
	// [.][.][.][.] -> [. .][. .] -> [. . . .]
	merge_insertion_sort_deque(deque, start, newEnd, groupSize * 2);

	// now our groups are pre-sorted, we need to merge them

	//builds main chain and pending list
	std::deque<int>	mainLine;
	std::deque<int>	pendingDeq;

	//push first two groups to main line since they are already sorted
	pushBackGroup(deque, mainLine, start, groupSize);
	pushBackGroup(deque, mainLine, start + groupSize, groupSize);

	for (size_t i = start + groupSize * 2; i < newEnd; i += groupSize * 2)
	{
		pushBackGroup(deque, pendingDeq, i, groupSize);
		pushBackGroup(deque, mainLine, i + groupSize, groupSize);
	}

	if (hasStrayElement)
		pushBackGroup(deque, pendingDeq, newEnd, groupSize);
	//insert pending elements to main line using binary search to find correct position using Jacobsthal numbers

	static const size_t jacobsthal[] = {
	1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731,
	5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051,
	1398101, 2796203, 5592405, 11184811, 22369621, 44739243,
	89478485, 178956971, 357913941, 715827883, 1431655765};

	size_t pendIndex = 0;
	size_t finalPendIndex = 0;
	size_t jacobIndex = 0;
	size_t groupsInserted = 0;
	size_t numPending = pendingDeq.size() / groupSize;

	while (groupsInserted < numPending)
	{
		jacobIndex++;
		pendIndex = jacobsthal[jacobIndex] - 1;
		if (pendIndex >= numPending)
			pendIndex = numPending - 1;

		while (finalPendIndex <= pendIndex && groupsInserted < numPending)
		{
			size_t searchLimit = pendIndex + 2 + groupsInserted;

			binaryInsertGroup(mainLine, pendingDeq,
				pendIndex * groupSize, searchLimit,
				groupSize);
			groupsInserted++;
			if (pendIndex == 0)
				break;
			pendIndex--;
		}
		finalPendIndex = jacobsthal[jacobIndex];
	}

	//update original deque
	for (size_t i = 0; i < mainLine.size(); i++)
		deque[start + i] = mainLine[i];

	// std::cout << COL_G << "Deque after sorting: ";
	// printContainer(deque);
	// std::cout << COL_X;
}
