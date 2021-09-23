/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLtree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:45:56 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/23 00:05:20 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "extras.hpp"

namespace ft
{
	template <typename T, typename Compare>
	class Tree
	{
		typedef size_t			size_type;
		
		typedef	T			value_type;
		
		typedef value_type*		pointer;
		
		typedef value_type const *	const_pointer;
		
		typedef value_type&		reference;
		
		typedef value_type const &	const_reference;
		
		struct Node
		{
			value_type value;
			Node *parent;
			Node *left;
			Node *right;

			Node(const_reference val=value_type()):
				value(val), parent(nullptr), left(nullptr), right(nullptr) {}
			Node(Node const &other):
				value(other.value), parent(nullptr), left(nullptr), right(nullptr) {}
		};
		
		typedef Node*			node_pointer;
	
		protected:
			node_pointer	_root;
			node_pointer	_begin;
			node_pointer	_end;
			Compare		_comp;

		public:
			Tree() :
				_root(nullptr),
				_begin(nullptr),
				_end(nullptr)
			{}

			Node* begin(void) const
			{return (this->_begin);}

			Node* end(void) const
			{return (this->_end);}
	};
}

#endif