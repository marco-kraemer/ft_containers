/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/18 20:08:52 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <utility>
#include "../container/extras/extras.hpp"

int main ()
{
	ft::Map<char,int> mymap;

	
	// show content:
	for (ft::Map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
	std::cout << it->first << " => " << it->second << '\n';

	return 0;
}