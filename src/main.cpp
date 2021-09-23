/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/23 00:04:56 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../container/extras/extras.hpp"

using namespace ft;

int	main(void)
{
	Tree<int, ft::less<int>> tree;

//	tree.insert(30);
//	std::cout << tree.end()->parent->parent->parent->parent->parent->value << std::endl;
	
	std::cout << tree.begin() << std::endl;
}