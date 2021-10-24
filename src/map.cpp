/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:45:12 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/24 14:53:05 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../container/extras/extras.hpp"

using namespace ft;

void	map_begin_end()
{
	map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	map_rbegin_rend()
{
	map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
}

void	map_empty()
{
	map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
}

void	map_size()
{
	map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
}

void	map_max_size()
{
	int i;
	map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";
}

void	map_tests(void)
{
	std::cout << "\nMap test begin() and end() \n" << std::endl;
	map_begin_end();
	std::cout << "\nMap test rbegin() and rend() \n" << std::endl;
	map_rbegin_rend();
	std::cout << "\nMap test empty()\n" << std::endl;
	map_empty();
	std::cout << "\nMap test size()\n" << std::endl;
	map_size();
	std::cout << "\nMap test max_size()\n" << std::endl;
	map_max_size();
}