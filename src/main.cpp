/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/15 12:01:21 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "../container/vector.hpp"

using namespace ft;

int main ()
{
	vector<int> myvector ((size_t)3,100);
	vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert (it , 200);
//	it = myvector.insert (it , 300);


	// "it" no longer valid, get a new one:
//	it = myvector.begin();

//	std::vector<int> anothervector (2,400);
//	myvector.insert (it+2,anothervector.begin(),anothervector.end());

//	int myarray [] = { 501,502,503 };
//	myvector.insert (myvector.begin(), myarray, myarray+3);
	it = myvector.begin();

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}