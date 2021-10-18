/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:12:00 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/18 20:56:19 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include "extras/extras.hpp"
namespace ft
{
	template <class Key, class T, class Compare=std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class Map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef std::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef unsigned long size_type;
			typedef BNode<key_type, mapped_type>* node;
			typedef MapIterator<key_type, mapped_type> iterator;
			typedef ReverseMapIterator<key_type, mapped_type> reverse_iterator;
			typedef ConstMapIterator<key_type, mapped_type> const_iterator;
			typedef ConstReverseMapIterator<key_type, mapped_type> const_reverse_iterator;
			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					};
			};
		private:
			allocator_type _allocator;
			key_compare _comp;
			node _root;
			size_type _length;

			void _debug_tree(node n)
			{
				if (!n)
					return;
				_debug_tree(n->left);
				if (n->parent && !n->end)
					std::cout << n->pair.first << "=" << n->pair.second << std::endl;
				_debug_tree(n->right);
			};

			node _new_node(key_type key, mapped_type value, node parent, bool end = false)
			{
				node New = new BNode<key_type, mapped_type>();
				New->pair = std::make_pair(key, value);
				New->right = 0;
				New->left = 0;
				New->parent = parent;
				New->end = end;
				return (New);
			};

			void _free_tree(node n)
			{
				if (n->right)
					_free_tree(n->right);
				if (n->left)
					_free_tree(n->left);
				delete n;
			};

			node _insert_node(node n, key_type key, mapped_type value, bool end = false)
			{
				if (n->end)
				{
					if (!n->left)
					{
						n->left = _new_node(key, value, n, end);
						return (n->left);
					}
					return (_insert_node(n->left, key, value));
				}
				if (key < n->pair.first && !end)
				{
					if (!n->left)
					{
						n->left = _new_node(key, value, n, end);
						return (n->left);
					}
					else
						return (_insert_node(n->left, key, value));
				}
				else
				{
					if (!n->right)
					{
						n->right = _new_node(key, value, n, end);
						return (n->right);
					}
					else
						return(_insert_node(n->right, key, value));
				}
			};

			node _find(node n, key_type key) const
			{
				node tmp;
				if (!n->end && n->pair.first == key && n->parent)
					return (n);
				if (n->right)
				{
					if ((tmp = _find(n->right, key)))
						return (tmp);
				}
				if (n->left)
				{
					if ((tmp = _find(n->left, key)))
						return (tmp);
				}
				return (0);
			};

			void _delete_node(node n)
			{
				node parent = n->parent;
				if (!n->left && !n->right)
				{
					if (parent->right == n)
						parent->right = 0;
					else
						parent->left = 0;
					delete n;
					return ;
				}
				if (n->right && !n->left)
				{
					if (parent->right == n)
						parent->right = n->right;
					else
						parent->left = n->right;
					n->right->parent = parent;
					delete n;
					return ;
				}
				if (n->left && !n->right)
				{
					if (parent->right == n)
						parent->right = n->left;
					else
						parent->left = n->left;
					n->left->parent = parent;
					delete n;
					return ;
				}
				node next = (++iterator(n)).node();
				if (!next)
					next = (--iterator(n)).node();
				ft::swap(next->pair, n->pair);
				_delete_node(next);
			};

			void _init_tree(void)
			{
				_root = _new_node(key_type(), mapped_type(), 0);
				_root->right  = _new_node(key_type(), mapped_type(), _root, true);
				_length = 0;
			};

			node _end(void) const
			{
				return (_root->right);
			};

		public:
			/* Constructors and desctructor */

			/*
			** Constructs a map container object, initializing its contents depending on the constructor version used:
			** Empty version
			*/
			explicit Map(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type())
			: _allocator(alloc), _comp(comp)
			{
				_init_tree();
			};

			/*
			** Constructs a map container object, initializing its contents depending on the constructor version used:
			** Range version
			*/
			template <class InputIterator>
			Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type())
			: _allocator(alloc), _comp(comp)
			{
				_init_tree();
				insert(first, last);
			};

			/*
			** Constructs a map container object, initializing its contents depending on the constructor version used:
			** Copy version
			*/
			Map(const Map<Key, T> &other)
			{
				_init_tree();
				*this = other;
			};

			/*
			** Destroys the container object.
			*/
			~Map(void)
			{
				_free_tree(_root);	
			};

			/*
			** Assigns new contents to the container, replacing its current content.
			*/
			Map &operator=(const Map<Key, T> &other)
			{
				clear();
				insert(other.begin(), other.end());
				return (*this);
			};

			/* Iterators */
			/*
			** Returns an iterator referring to the first element in the map container.
			** Because map containers keep their elements ordered at all times,
			** begin points to the element that goes first following the container's sorting criterion.
			** If the container is empty, the returned iterator value shall not be dereferenced.
			*/
			iterator begin()
			{
				node	tmp;
			
				tmp = this->_root;
				if (!tmp->left && !tmp->right)
					return (end());
				if (!tmp->left && tmp->right)
					tmp = tmp->right;
				while (tmp->left)
					tmp = tmp->left;
				return (iterator(tmp));			
			}
	
			/*
			** Returns a const iterator referring to the first element in the map container.
			** Because map containers keep their elements ordered at all times,
			** begin points to the element that goes first following the container's sorting criterion.
			** If the container is empty, the returned iterator value shall not be dereferenced.
			*/
			const_iterator begin() const
			{
				node	tmp;
			
				tmp = this->_root;
				if (!tmp->left && !tmp->right)
					return (end());
				if (!tmp->left && tmp->right)
					tmp = tmp->right;
				while (tmp->left)
					tmp = tmp->left;
				return (const_iterator(tmp));	
			}

			/*
			** Returns an iterator referring to the past-the-end element in the ma
			*/
			iterator end()
			{return (iterator(this->_end()));}

			/*
			** Returns a const iterator referring to the past-the-end element in the ma
			*/
			const_iterator end() const
			{return (const_iterator(this->_end()));}

			/* Capacity */

			/*
			** Returns whether the map container is empty.
			** This function does not modify the container in any way.
			*/
			bool empty() const
			{return (this->_length == 0);}

			/* Element access */

			/*
			** If k matches the key of an element in the container, the function returns a reference to its mapped value.
			** If k does not match the key of any element in the container, the function inserts a new element with that key and returns a reference to its mapped value.
			** Notice that this always increases the container size by one
			*/
//			mapped_type& operator[] (const key_type& k)
//			{
//			}

			/* Modifiers */

			/*
			** Extends the container by inserting new elements,
			** effectively increasing the container size by the number of elements inserted.
			** Single element case
			*/
			std::pair<iterator,bool> insert (const value_type& val)
			{
				iterator	tmp;

				tmp = find(val.first);
				if (tmp != end())
					return (std::make_pair(tmp, false));
				this->_length += 1;
				return (std::make_pair(iterator(_insert_node(this->_root, val.first, val.second)), true));
			}

			/*
			** Extends the container by inserting new elements,
			** effectively increasing the container size by the number of elements inserted.
			** With hint case
			*/
			iterator insert (iterator position, const value_type& val)
			{
				iterator	tmp;

				tmp = find(val.first);
				if (tmp != end())
					return (tmp);
				this->_length += 1;
				return (iterator(_insert_node(position.node(), val.first, val.second)));
			}

			/*
			** Extends the container by inserting new elements,
			** effectively increasing the container size by the number of elements inserted.
			** Range case
			*/
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}
			
			/*
			** Removes all elements from the map container (which are destroyed),
			** leaving the container with a size of 0.
			*/
			void clear();

			/* Observers */

			/* Operations */
			
			/*
			** Searches the container for an element with a key equivalent to k and returns an iterator to it if found.
			** Otherwise it returns an iterator to map::end.
			*/
			iterator find (const key_type& k)
			{
				node	tmp;
			
				tmp = _find(this->_root, k);
				if (!(tmp) || empty())
					return (end());
				return (iterator(tmp));
			}

			/*
			** Searches the container for an element with a key equivalent to k and returns an iterator to it if found.
			** Otherwise it returns an iterator to map::end.
			*/
			const_iterator find (const key_type& k) const
			{
				node	tmp;
			
				tmp = _find(this->_root, k);
				if (!(tmp) || empty())
					return (end());
				return (const_iterator(tmp));	
			}
			
			/* Allocator */

	};
	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::Map<Key, T, Compare, Alloc> &x, ft::Map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::Map<Key, T, Compare, Alloc>::const_iterator it = rhs.begin();
		typename ft::Map<Key, T, Compare, Alloc>::const_iterator it2 = lhs.begin();
		while (it != rhs.end())
		{
			if (*it != *it2)
				return (false);
			++it2;
			++it;
		}
		return (true);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() > rhs.size())
			return (true);
		typename ft::Map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
		typename ft::Map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
		while (it != lhs.end() && it2 != rhs.end())
		{
			if (*it > *it2)
				return (true);
			++it2;
			++it;
		}
		return (false);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs > rhs) && !(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs > rhs));
	};
};

#endif