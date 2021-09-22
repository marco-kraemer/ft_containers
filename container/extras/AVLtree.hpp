/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVLtree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:45:56 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/22 14:33:44 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "extras.hpp"

namespace ft
{

	/*
	** AVL tree is a self-balancing Binary Search Tree (BST)
	** where the difference between heights of left and right subtrees cannot be more than one for all nodes. 
	*/

	class Node
	{
		public:
			int key;
			Node *left;
			Node *right;
			int height;
	};

	class avl_tree
	{
		public:
			/*
			** Get maximum of two integers
			*/
			int max(int a, int b)
			{
				if (a > b)
					return (a);
				return (b);
			}

			/*
			** Get height of the tree
			*/
			int height(Node *N)
			{
				if (N == NULL)
					return 0;
				return (N->height);
			}

			/*
			**  Alloc new node with the given key
			*/
			Node *newNode(int key)
			{
				Node *node = new Node();
				node->key = key;
				node->left = NULL;
				node->right = NULL;
				node->height = 1;
				return (node);
			}
		
			/*
			** Rotate AVL tree to the right
			*/
			Node *rightRotate(Node *y)
			{
				Node *x = y->left;
				Node *T2 = x->right;

				x->right = y;
				y->left = T2;

				y->height = max(height(y->left), height(y->right)) + 1;
				x->height = max(height(x->left), height(x->right)) + 1;

				return (x);
			}

			/*
			** Rotate AVL tree to the left
			*/			
			Node *leftRotate(Node *x)
			{
				Node *y = x->right;
				Node *T2 = y->left;
				
				y->left = x;
				x->right = T2;
				
				x->height = max(height(x->left), height(x->right)) + 1;
				y->height = max(height(y->left), height(y->right)) + 1;
				
				return (y);
			}

			/*
			** Get the difference height between nodes
			*/
			int getBalance(Node *N)
			{
				if (N == NULL)
					return (0);
				return (height(N->left) - height(N->right));
			}

			/*
			** Recursive function to insert an element
			** and balance the tree, if necessary
			*/
			Node *insert(Node *node, int key)
			{
				if (node == NULL)
					return (newNode(key));

				if (key < node->key)
					node->left = insert(node->left, key);
				else if (key > node->key)
					node->right = insert(node->right, key);
				else
					return (node);
				
				node->height = 1 + max(height(node->left), height(node->right));
				int balance = getBalance(node);

				// Left Left Case
				if (balance > 1 && key < node->left->key)
					return (rightRotate(node));

				// Right Right Case
				if (balance < -1 && key > node->right->key)
					return (leftRotate(node));

				// Left Right Case
				if (balance > 1 && key > node->left->key)
				{
					node->left = leftRotate(node->left);
					return (rightRotate(node));
				}

				// Right Left Case
				if (balance < -1 && key < node->right->key)
				{
					node->right = rightRotate(node->right);
					return (leftRotate(node));
				}

				return (node);
			}

			void preOrder(Node *root)
			{
				if(root != NULL)
				{
					std::cout << root->key << " ";
					preOrder(root->left);
					preOrder(root->right);
				}
			}

	};
}

#endif