/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:52:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/22 15:26:12 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../container/extras/extras.hpp"

using namespace ft;

int main ()
{
	ft::map<int, int> first;

	first[1] = 1;
	
	/*
	ft::avl_tree Avl;
	ft::Node *root;

	root = Avl.insert(root, 10);
	root = Avl.insert(root, 20);
	root = Avl.insert(root, 30);
	root = Avl.insert(root, 40);
	root = Avl.insert(root, 50);
	root = Avl.insert(root, 25);

	std::cout << "Preorder traversal of the "
		"constructed AVL tree is \n";
	Avl.preOrder(root);
	*/
	return 0;
}