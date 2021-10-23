/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/23 15:07:48 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <map>
# include <utility>
# include <stack>
# include <vector>
# include <iostream>
# include <iterator>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
#include "../container/extras/extras.hpp"

#include <iostream>
#include <string>
#include <deque>
#include <stdlib.h>

using namespace ft;

void	vec_begin_end()
{
	vector<int> myvector;
	for (int i=1; i<=5; i++)
		myvector.push_back(i);

	std::cout << "myvector contains:";
	for (vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	vec_size()
{
	vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(), (size_t)10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}

void	vec_max_size()
{
	vector<int> myvector;

	for (int i=0; i<100; i++) 
		myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}

void	vec_resize()
{
	vector<int> myvector;

	// set some initial content:
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (int i = 0; i < (int)myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	vec_capacity()
{
	vector<char> myvector;

	for (int i = 0; i < 100; i++)
		myvector.push_back('a');

	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector.max_size() << '\n';
}

void	vec_empty()
{
	vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++)
		myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total: " << sum << '\n';
}

void	vec_reserve()
{
	vector<int>::size_type sz;

	vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
			foo.push_back(i);
		if (sz!=foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		if (sz!=bar.capacity())
		{
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void	vector_tests()
{
	std::cout << "\n\nVector test begin() and end() \n" << std::endl;
	vec_begin_end();
	std::cout << "\n\nVector test size() \n" << std::endl;
	vec_size();
	std::cout << "\n\nVector test max_size() \n" << std::endl;
	vec_max_size();
	std::cout << "\n\nVector test resize() \n" << std::endl;
	vec_resize();
	std::cout << "\n\nVector test capacity() \n" << std::endl;
	vec_capacity();	
	std::cout << "\n\nVector test empty() \n" << std::endl;
	vec_empty();
	std::cout << "\n\nVector test reserve() \n" << std::endl;
	vec_reserve();
}

int	main(void)
{
	vector_tests();
}