/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:50:03 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/11 12:30:09 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <iostream>
# include <vector>
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

# include "extras/random_access_iterator.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{	
		public:
			typedef T					value_type;
			typedef Alloc					allocator_type;
			typedef T*					pointer;
			typedef T&					reference;
			typedef typename allocator_type::size_type	size_type;
			typedef random_access_iterator<T>		iterator;

			// Constructors

			/*
			** Empty container constructor (default constructor)
			** Constructs an empty container, with no elements.
			*/
			explicit vector (const allocator_type& alloc = allocator_type()) :
				_first(nullptr),
				_last(nullptr),
				_capacity(nullptr),
				_alloc(alloc) 
			{}

			/*
			** Fill constructor
			** Constructs a container with n elements. Each element is a copy of val.
			*/
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) :
				_first(nullptr),
				_last(nullptr),
				_capacity(nullptr),
				_alloc(alloc) 
			{
				_first = _alloc.allocate(n);
				_capacity = _first + n;
				_last = _first;
				for (int length = 0; length < n; length++)
				{
					alloc.construct(_last, val);
					_last++;
				}
			}

			/*
			** Range constructor
			** Constructs a container with as many elements as the range [first,last),
			** with each element constructed from its corresponding element in that range, in the same order.
			*/
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type()) :
				_alloc(alloc)
			{
				int	range = 0;

				while (first != last)
				{
					first++;
					range++;
				}
				_first = _alloc.allocate(range);		
				_capacity = _first + range;
				_last = _first;
				while (range--)
				{
					_alloc.construct(_last, *first++);
					_last++;
				}

			}

			/*
			** Copy constructor
			** Constructs a container with a copy of each of the elements in x, in the same order.
			*/
			vector (const vector& x) :
			_first(nullptr),
			_last(nullptr),
			_capacity(nullptr),
			_alloc(x._alloc) 
			{
				this->insert()
			}

			// Destructors
			
			/*
			** This destroys all container elements,
			** and deallocates all the storage capacity allocated by the vector using its allocator.
			*/
			~vector()
			{
				_alloc.deallocate(_first, this->capacity());
			}

			// Operator =

			/*
			** Assigns new contents to the container,
			** replacing its current contents, and modifying its size accordingly.
			*/
			vector& operator= (const vector& x)
			{
				size_type	storage = this->size();
				pointer		old_first = x._first;

				this->_first = this->_alloc.allocate(storage);
				this->_last = this->_first;
				while (old_first != x._last)
				{
					this->_last = x._first;
					this->_last++;
					old_first++;
				}
				return (*this);
			}

			// Iterators

			// Capacity

			/*
			** Returns the number of elements in the vector.
			*/
			size_type size() const
			{return (_last - _first);}

			/*
			** Returns the size of the storage space currently allocated for the vector,
			** expressed in terms of elements.
			** This capacity is not necessarily equal to the vector size. It can be equal or greater,
			** with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
			*/
			size_type capacity() const
			{return (this->_capacity - this->_first);}	

			/*
			** Requests that the vector capacity be at least enough to contain n elements.
			** If n is greater than the current vector capacity,
			** the function causes the container to reallocate its storage increasing its capacity to n (or greater).
			** In all other cases, the function call does not cause a reallocation
			** and the vector capacity is not affected.
			*/
			void reserve (size_type n)
			{
				pointer		old_first = _first;
				pointer		old_last = _last;
				size_type	old_size = this->size();
				size_type	old_capacity = this->capacity();

				_first = _alloc.allocate(n);
				_last = _first;
				_capacity = _first + n;
				while (old_first != old_last)
				{
					_alloc.construct(_last, *old_first);
					_last++;
					old_first++;
				}
				_alloc.deallocate(old_first - old_size, old_capacity);
			}

			// Element Access

			/*
			** Returns a reference to the element at position n in the vector container.
			*/
			reference operator[] (size_type n)
			{return (*(_first + n));}

			// Modifiers

			/*
			** Adds a new element at the end of the vector, after its current last element.
			** The content of val is copied (or moved) to the new element.
			*/		
			void push_back (const value_type& val)
			{
				if (_last == _capacity)
				{
					int	new_capacity;
	
					if (size() == 0)
						new_capacity = 1;
					else
						new_capacity = (this->size() * 2);
					this->reserve(new_capacity);
				}
				_alloc.construct(_last, val);
				_last++;
			}

			/*
			** The vector is extended by inserting new elements before the element at the specified position,
			** effectively increasing the container size by the number of elements inserted.
			** This causes an automatic reallocation of the allocated storage.
			** @param position The position where insert.
			** @param val The element to insert.
			** @return An iterator to the new element in the container.
			*/		
			iterator insert (iterator position, const value_type& val)
			{

			}

			/*
			** The vector is extended by inserting new elements before the element at the specified position,
			** effectively increasing the container size by the number of elements inserted.
			** This causes an automatic reallocation of the allocated storage.
			** @param position The position where insert.
			** @param n amount elements to insert.
			** @param val The element to insert.
			*/			
			void insert (iterator position, size_type n, const value_type& val)
			{
				
			}

			// Allocator


			// Remove Later
			size_type get_size()
			{
				return (this->size());
			}
			size_type get_capacity()
			{
				return (this->capacity());
			}

		private:
			pointer		_first;
			pointer		_last;
			pointer		_capacity;
			allocator_type	_alloc;
	};
}

#endif