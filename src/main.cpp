/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/22 20:09:10 by maraurel         ###   ########.fr       */
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

void	check_elements(vector<int> my_vec)
{
	std::cout << "See all elements" << std::endl;
	vector<int>::iterator	it_vec;
	it_vec = my_vec.begin();
	while (it_vec != my_vec.end())
	{
		std::cout << *it_vec << ", ";
		it_vec++; 
	}
	std::cout << "\n";
}

void	vector_tests()
{
	std::cout << "--------------------------------- Vector Tests ---------------------------------" << std::endl;
	vector<int>	my_vec;

	std::cout << "My vector size: " << my_vec.size() << std::endl;
	if (my_vec.empty())
		std::cout << "Vector is empty" << std::endl;
	else
		std::cout << "Vector is not empty" << std::endl;
	
	my_vec.push_back(1);
	my_vec.push_back(2);
	my_vec.push_back(3);
	my_vec.push_back(4);
	
	std::cout << "My vector size: " << my_vec.size() << std::endl;
	if (my_vec.empty())
		std::cout << "Vector is empty" << std::endl;
	else
		std::cout << "Vector is not empty" << std::endl;
	check_elements(my_vec);

	std::cout << "\n\n*** Insert Elements ***" << std::endl;

	std::cout << "Insert '500' in begin() + 2 position" << std::endl;
	my_vec.insert(my_vec.begin() + 2, 500);
	check_elements(my_vec);

	std::cout << "Insert '200' 3 times in end()  position" << std::endl;
	my_vec.insert(my_vec.end(), (size_t) 3, 200);
	check_elements(my_vec);
}

int	main(void)
{
	vector_tests();
}