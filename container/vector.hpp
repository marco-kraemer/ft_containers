/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:50:03 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/09 11:48:19 by maraurel         ###   ########.fr       */
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
			typedef	typename allocator_type::size_type	size_type;

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
			vector (const vector& x)
			{
				pointer	tmp;
				int	length;
		
				tmp = x._first;
				length = 0;
				while (x._first != x._last)
				{
					x._first++;
					length++;
				}
				x._first = tmp;
				this->_first = this->_alloc.allocate(length);
				while (x._first != x._last)
				{
					this->_first = x._first;
					this->_first++;
					x._first++;
				}
			}

			// Iterators

			// Capacity

			/*
			** Returns the number of elements in the vector.
			*/
			size_type size() const
			{return (_last - _first);}

			/*
			** Requests that the vector capacity be at least enough to contain n elements.
			** If n is greater than the current vector capacity,
			** the function causes the container to reallocate its storage increasing its capacity to n (or greater).
			** In all other cases, the function call does not cause a reallocation
			** and the vector capacity is not affected.
			*/
			void reserve (size_type n)
			{

			}

			// Element Access

			/*
			** Returns a reference to the element at position n in the vector container.
			*/
			reference operator[] (size_type n)
			{
				return (*(_first + n));
			}

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
						new_capacity = 1
					else
						new_capacity = (this->size() * 2)
					this->reserve(new_capacity);
				}
				_alloc.construct(_last, val);
				_last++;
			}

			// Allocator

		private:
			pointer		_first;
			pointer		_last;
			pointer		_capacity;
			allocator_type	_alloc;
	};
}

#endif