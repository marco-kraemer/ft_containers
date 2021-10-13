/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:37:20 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/13 19:16:39 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_HPP
#define EXTRAS_HPP

# include <iostream>

# include "./random_access_iterator.hpp"
# include "./BST_tree.hpp"
# include "../vector.hpp"
# include "../map.hpp"
# include "./BST_iterator.hpp"

namespace ft
{
    template <typename T>
    struct BST_Node
    {
        public :

            typedef T   value_type;

            value_type value;
            BST_Node* parent;
            BST_Node* left;
            BST_Node* right;

            BST_Node ()
            :
                value(),
                parent(u_nullptr),
                left(u_nullptr),
                right(u_nullptr)
            {}

            BST_Node (BST_Node* parent = u_nullptr,
                    BST_Node* left = u_nullptr, BST_Node* right = u_nullptr)
            :
                value(),
                parent(parent),
                left(left),
                right(right)
            {}
            
            BST_Node (const value_type& val, BST_Node* parent = u_nullptr,
                    BST_Node* left = u_nullptr, BST_Node* right = u_nullptr)
            :
                value(val),
                parent(parent),
                left(left),
                right(right)
            {}

            BST_Node (const BST_Node& nd)
            :
                value(nd.value),
                parent(nd.parent),
                left(nd.left),
                right(nd.right)
            {}

            virtual ~BST_Node() {}

            BST_Node &operator=(const BST_Node& nd)
            {
                if (nd == *this)
                    return (*this);
                
                this->value = nd.value;
                this->parent = nd.parent;
                this->left = nd.left;
                this->right = nd.right;
                
                return (*this);
            }

            bool operator==(const BST_Node& nd)
            {
                if (value == nd.value)
                    return (true);
                return (false);
            }
    };

    template <class T1, class T2>
        ft::pair<T1,T2> make_pair(T1 x, T2 y)
        {
            return (ft::pair<T1, T2>(x, y));
        };
}

#endif