/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:12:00 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/26 17:16:20 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include "extras/includes.hpp"
namespace ft
{
	template <class Key, class T, class Compare=less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
	class map
	{
		public:
			typedef Key 							key_type;

			typedef T							mapped_type;

			typedef pair<const key_type, mapped_type>			value_type;

			typedef Compare							key_compare;

			typedef Alloc							allocator_type;

			typedef T&							reference;

			typedef const T&						const_reference;

			typedef T*							pointer;

			typedef const T*						const_pointer;

			typedef MapIterator<key_type, mapped_type>			iterator;

			typedef const MapIterator<key_type, mapped_type>		const_iterator;

			typedef ReverseMapIterator<key_type, mapped_type>		reverse_iterator;

			typedef const ReverseMapIterator<key_type, mapped_type>		const_reverse_iterator;
		
			typedef size_t							size_type;

			typedef BNode<key_type, mapped_type>*				node;

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
			allocator_type	_allocator;
			key_compare	_comp;
			node		_root;
			size_type	_length;

			node create_node(key_type key, mapped_type value, node parent, bool end = false)
			{
				node New = new BNode<key_type, mapped_type>();
				New->pair = ft::make_pair(key, value);
				New->right = 0;
				New->left = 0;
				New->parent = parent;
				New->end = end;
				return (New);
			};

			void free_bst(node n)
			{
				if (n->right)
					free_bst(n->right);
				if (n->left)
					free_bst(n->left);
				delete n;
			};

			node insert_node(node n, key_type key, mapped_type value, bool end = false)
			{
				if (n->end)
				{
					if (!n->left)
					{
						n->left = create_node(key, value, n, end);
						return (n->left);
					}
					return (insert_node(n->left, key, value));
				}
				if (key < n->pair.first && !end)
				{
					if (!n->left)
					{
						n->left = create_node(key, value, n, end);
						return (n->left);
					}
					else
						return (insert_node(n->left, key, value));
				}
				else
				{
					if (!n->right)
					{
						n->right = create_node(key, value, n, end);
						return (n->right);
					}
					else
						return(insert_node(n->right, key, value));
				}
			};

			node find_node(node n, key_type key) const
			{
				node tmp;
				if (!n->end && n->pair.first == key && n->parent)
					return (n);
				if (n->right)
				{
					if ((tmp = find_node(n->right, key)))
						return (tmp);
				}
				if (n->left)
				{
					if ((tmp = find_node(n->left, key)))
						return (tmp);
				}
				return (0);
			};

			void delete_node(node n)
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
				delete_node(next);
			};

			void create_bst(void)
			{
				_root = create_node(key_type(), mapped_type(), 0);
				_root->right  = create_node(key_type(), mapped_type(), _root, true);
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
			explicit map(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type())
			: _allocator(alloc), _comp(comp)
			{
				create_bst();
			}

			/*
			** Constructs a map container object, initializing its contents depending on the constructor version used:
			** Range version
			*/
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type())
			: _allocator(alloc), _comp(comp)
			{
				create_bst();
				insert(first, last);
			}

			/*
			** Constructs a map container object, initializing its contents depending on the constructor version used:
			** Copy version
			*/
			map(const map<Key, T> &other)
			{
				create_bst();
				*this = other;
			}

			/*
			** Destroys the container object.
			*/
			~map(void)
			{free_bst(_root);}

			/*
			** Assigns new contents to the container, replacing its current content.
			*/
			map &operator=(const map<Key, T> &other)
			{
				clear();
				insert(other.begin(), other.end());
				return (*this);
			}

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
			** Returns an iterator referring to the past-the-end element in the map container.
			*/
			iterator end()
			{return (iterator(this->_end()));}

			/*
			** Returns a const iterator referring to the past-the-end element in the map container.
			*/
			const_iterator end() const
			{return (const_iterator(this->_end()));}

			/*
			** Returns a reverse iterator pointing to the last element in the container.
			*/
			reverse_iterator rbegin()
			{
				reverse_iterator tmp = this->_end();
			
				tmp++;
				return (tmp);
			}

			/*
			** Returns a const reverse iterator pointing to the last element in the container.
			*/
			const_reverse_iterator rbegin() const
			{
				const_reverse_iterator tmp = this->_end();
			
				tmp++;
				return (tmp);
			}

			/*
			** Returns a reverse iterator pointing to the theoretical element right before the first element in the map container.
			*/
			reverse_iterator rend()
			{return (reverse_iterator(_root));}

			/*
			** Returns a const reverse iterator pointing to the theoretical element right before the first element in the map container.
			*/
			const_reverse_iterator rend() const
			{return (const_reverse_iterator(_root));}
			
			/* Capacity */

			/*
			** Returns whether the map container is empty.
			** This function does not modify the container in any way.
			*/
			bool empty() const
			{return (this->_length == 0);}

			/*
			** Returns the number of elements in the map container.
			*/
			size_type size() const
			{return (this->_length);}

			/*
			** Returns the maximum number of elements that the map container can hold.
			*/
			size_type max_size() const
			{return (allocator_type().max_size());}

			/* Element access */

			/*
			** If k matches the key of an element in the container, the function returns a reference to its mapped value.
			** If k does not match the key of any element in the container, the function inserts a new element with that key and returns a reference to its mapped value.
			** Notice that this always increases the container size by one
			*/
			mapped_type& operator[] (const key_type& k)
			{
				iterator	tmp;
			
				tmp = find(k);
				if (tmp != end())
					return (tmp->second);
				return (insert((value_type) ft::make_pair(k, mapped_type())).first->second);
			}

			/* Modifiers */

			/*
			** Extends the container by inserting new elements,
			** effectively increasing the container size by the number of elements inserted.
			** Single element case
			*/
			pair<iterator,bool> insert (const value_type& val)
			{
				iterator	tmp;

				tmp = find(val.first);
				if (tmp != end())
					return (ft::make_pair(tmp, false));
				this->_length += 1;
				return (ft::make_pair(iterator(insert_node(this->_root, val.first, val.second)), true));
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
				return (iterator(insert_node(position.node(), val.first, val.second)));
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
			** Removes from the map container either a single element or a range of elements ([first,last)).
			** This effectively reduces the container size by the number of elements removed, which are destroyed.
			*/
			void erase (iterator position)
			{
				delete_node(position.node());
				this->_length--;
			}

			/*
			** Removes from the map container either a single element or a range of elements ([first,last)).
			** This effectively reduces the container size by the number of elements removed, which are destroyed.
			*/	
			size_type erase (const key_type& k)		
			{
				iterator	tmp;

				tmp = find(k);
				if (tmp == end())
					return (0);
				delete_node(tmp.node());
				this->_length--;
				return (1);				
			}
				
			/*
			** Removes from the map container either a single element or a range of elements ([first,last)).
			** This effectively reduces the container size by the number of elements removed, which are destroyed.
			*/		
			void erase (iterator first, iterator last)		
			{
				while (first != last)
					erase(first++);
			}	
			
			/*
			** Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
			** After the call to this member function, the elements in this container are those which were in x before the call,
			** and the elements of x are those which were in this.
			** All iterators, references and pointers remain valid for the swapped objects.
			*/
			void swap (map& x)
			{
				node		tmp;
				size_t		tmp_length;

				tmp_length	= x._length;
				x._length	= this->_length;
				this->_length	= tmp_length;

				tmp		= x._root;
				x._root		= this->_root;
				this->_root	= tmp;
			}

			/*
			** Removes all elements from the map container (which are destroyed),
			** leaving the container with a size of 0.
			*/
			void clear()
			{erase(begin(), end());}

			/* Observers */
			
			/*
			** Returns a copy of the comparison object used by the container to compare keys.
			** The comparison object of a map object is set on construction.
			*/
			key_compare key_comp() const
			{return (this->_comp);}

			/*
			** Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
			** The arguments taken by this function object are of member type value_type.
			*/
			value_compare value_comp() const
			{return (this->value_comp);}

			/* Operations */
			
			/*
			** Searches the container for an element with a key equivalent to k and returns an iterator to it if found.
			** Otherwise it returns an iterator to map::end.
			*/
			iterator find (const key_type& k)
			{
				node	tmp;
			
				tmp = find_node(this->_root, k);
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
			
				tmp = find_node(this->_root, k);
				if (!(tmp) || empty())
					return (end());
				return (const_iterator(tmp));	
			}

			/*
			** Searches the container for elements with a key equivalent to k and returns the number of matches.
			** Because all elements in a map container are unique, the function can only return 1 or 0.
			*/
			size_type count(const key_type& k)
			{
				iterator	tmp;
				
				tmp = find(k);
				if (tmp == end())
					return (0);
				return (1);
			}

			/*
			** Returns an iterator pointing to the first element in the container whose key is not considered to go before
			*/
			iterator lower_bound (const key_type& k)
			{
				iterator	tmp;
			
				tmp = begin();
				while (tmp != end())
				{
					if (_comp(tmp->first, k) <= 0)
						return (tmp);
					tmp++;
				}
				return (tmp);
			}

			/*
			** Returns a const iterator pointing to the first element in the container whose key is not considered to go before
			*/
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator	tmp;
			
				tmp = begin();
				while (tmp != end())
				{
					if (_comp(tmp->first, k) <= 0)
						return (tmp);
					tmp++;
				}
				return (tmp);
			}

			/*
			** Returns an iterator pointing to the first element in the container whose key is considered to go after k.
			*/
			iterator upper_bound (const key_type& k)
			{
				iterator tmp = find(k);
				if (tmp == end())
					return (tmp);
				tmp++;
				return (tmp);
			}

			/*
			** Returns a const iterator pointing to the first element in the container whose key is considered to go after k.
			*/
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator tmp = find(k);
				if (tmp == end())
					return (tmp);
				tmp++;
				return (tmp);
			}

			/*
			** Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
			** If no matches are found, the range returned has a length of zero,
			** with both iterators pointing to the first element that has a key considered to go
			** after k according to the container's internal comparison object (key_comp).
			*/
			pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{return (pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));}

			/*
			** Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
			** If no matches are found, the range returned has a length of zero,
			** with both iterators pointing to the first element that has a key considered to go
			** after k according to the container's internal comparison object (key_comp).
			*/
			pair<iterator, iterator> equal_range(const key_type &k)
			{return (pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));}
			
			/* Allocator */
			allocator_type get_allocator() const
			{return (this->_allocator);}

	};
};

#endif