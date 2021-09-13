/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/13 19:52:35 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../container/vector.hpp"

using namespace ft;

int main2(void)
{
	vector<int>	vec1;
	vec1.push_back(2);
	vec1.push_back(5);
	vec1.push_back(10);
	vector<int>	vec2(vec1);
	for (int i = 0; vec2[i]; i++)
		std::cout << "Element " << i << ": " << vec2[i] << std::endl;
	std::cout << "Size:" << vec2.get_size() << "\nMax Size: " << vec2.max_size() << std::endl;
	return (0);
}

int main ()
{
	vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';

	return 0;
}