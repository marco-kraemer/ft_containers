/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:26:10 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/13 17:37:26 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_TREE_HPP
#define BST_TREE_HPP

#include "./extras.hpp"

namespace ft
{
	template <class T, class Compare = ft::less<T>, class Node = ft::BST_Node<T>,
		class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
	class bst
	{
	};
}

#endif