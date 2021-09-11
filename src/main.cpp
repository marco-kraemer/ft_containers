/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/11 14:30:37 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../container/vector.hpp"

using namespace ft;

int main(void)
{
	vector<int>	vec1;
	vec1.push_back(5);
	vec1.push_back(2);
	vec1.push_back(8);
	vector<int>	vec2(vec1);
	std::cout << *(vec1.end() - 1) << std::endl;
}