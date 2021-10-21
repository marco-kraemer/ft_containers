/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/21 14:23:55 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <utility>
#include "../container/extras/extras.hpp"

using namespace ft;

int main ()
{
	map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	pair<map<char,int>::iterator, map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	return 0;
}