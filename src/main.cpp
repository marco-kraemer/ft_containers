/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/22 22:46:22 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../container/extras/extras.hpp"

using namespace ft;

int main()
{
	avl_tree	avl;

	avl.newNode(0, 10);
	avl.newNode(1, 20);
	avl.newNode(2, 30);	
	std::cout << "Preorder traversal of the "
		"constructed AVL tree is \n";

	return 0;
}