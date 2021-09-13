/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/13 19:32:11 by maraurel         ###   ########.fr       */
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
	vector<int> myvector (10);

	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i) = i * 2;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';

	return 0;
	}