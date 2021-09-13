/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/13 18:38:22 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../container/vector.hpp"

using namespace ft;

int main(void)
{
	vector<int>	vec1;
	vec1.push_back(2);
	vec1.push_back(5);
	vec1.push_back(10);
	vector<int>	vec2(vec1);
	for (int i = 0; vec2[i]; i++)
		std::cout << "Element " << i << ": " << vec2[i] << std::endl;
	std::cout << "Size:" << vec2.get_size() << std::endl;
}