/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:22:46 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/25 14:33:47 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../container/extras/extras.hpp"

using namespace ft;

void	stack_empty(void)
{
	stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++)
		mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	std::cout << "total: " << sum << '\n';
}

void	stack_size()
{
	stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
}

void	stack_top()
{
	stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void	stack_push()
{
	stack<int> mystack;

	for (int i=0; i<5; ++i)
		mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

void	stack_pop()
{
	stack<int> mystack;

	for (int i=0; i<5; ++i)
		mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

void	stack_tests(void)
{
	std::cout << "\n------------------------------ TESTING STACK CONTAINER -----------------------------------------------" << std::endl;
	std::cout << "\nStack test empty() \n" << std::endl;
	stack_empty();
	std::cout << "\nStack test size() \n" << std::endl;
	stack_size();
	std::cout << "\nStack test top() \n" << std::endl;
	stack_top();
	std::cout << "\nStack test push() \n" << std::endl;
	stack_push();
	std::cout << "\nStack test pop() \n" << std::endl;
	stack_pop();
}