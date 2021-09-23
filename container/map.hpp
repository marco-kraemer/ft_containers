/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:12:00 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/22 23:35:56 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include "extras/extras.hpp"

namespace ft
{
	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		typedef Arg1 first_argument_type;
		typedef Arg2 second_argument_type;
		typedef Result result_type;
	};

	template <class T>
	struct less : binary_function <T,T,bool>
	{
		bool operator() (const T& x, const T& y) const {return x<y;}
	};

	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;
	
		first_type	first;
		second_type	second;

		pair() : first(), second()
		{}

		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)
		{}

		pair (const first_type& a, const second_type& b) : first(a), second(b)
		{}

		pair& operator= (const pair& pr)
		{
			this->first = pr.first;
			this->second = pr.second;
			return (*this);	
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first != rhs.first && lhs.second != rhs.second);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first <= rhs.first && lhs.second <= rhs.second);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first > rhs.first && lhs.second > rhs.second);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first >= rhs.first && lhs.second >= rhs.second);
	};
}


namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
	
	class map
	{
		public:
			typedef Key						key_type;
			
			typedef T						mapped_type;
			
			typedef ft::pair<const key_type, mapped_type>		value_type;
			
			typedef Compare						key_compare;
		
			class 							value_compare
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}

				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{return comp(x.first, y.first);}
			};
			
			typedef Alloc						allocator_type;
			
			typedef typename allocator_type::reference		reference;
			
			typedef typename allocator_type::const_reference	const_reference;
			
			typedef typename allocator_type::pointer		pointer;
			
			typedef typename allocator_type::const_pointer		const_pointer;
			
			typedef random_access_iterator<T>			iterator;
		
			typedef const random_access_iterator<T>			const_iterator;

			typedef size_t						size_type;
		
			// Constructors / Destructors

			/*
			** Empty container constructor (default constructor)
			** Constructs an empty container, with no elements.
			*/
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_alloc(nullptr),
				_tree()
			{}
			
			/*
			** Range constructor
			** Constructs a container with as many elements as the range [first,last),
			** with each element constructed from its corresponding element in that range, in the same order.
			*/
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_alloc(alloc),
				_comp(comp),
				_tree()
			{}
			
			/*
			** Copy constructor
			** Constructs a container with a copy of each of the elements in x, in the same order.
			*/
			map (const map& x) :
				_alloc(x._alloc),
				_value(x._value),
				_tree()
			{}

			/*
			** This destroys all container elements,
			** and deallocates all the storage capacity allocated by the map container using its allocator.
			*/
			~map()
			{}
			
			/*
			** The elements stored in the container before the call are either assigned to or destroyed.
			*/
			map& operator= (const map& x)
			{
				this->_tree = x._tree;
				this->_alloc = x._alloc;
				return (*this);
			}

			// Iterators
			
			/*
			** Returns an iterator referring to the first element in the map container.
			*/
//			iterator begin()
//			{
//				return ();
//			}
			
			// Capacity

			// Element Access

			/*
			** If k matches the key of an element in the container, the function returns a reference to its mapped value.
			** If k does not match the key of any element in the container,
			** the function inserts a new element with that key and returns a reference to its mapped value
			*/
			mapped_type& operator[] (const key_type& k)
			{}

			// Modifiers

			// Observers

			// Operations

			// Allocator

		private:
			Tree<value_type, Compare>	_tree;
			allocator_type			_alloc;
			value_type			_value;
			Compare				_comp;
	};
}

#endif