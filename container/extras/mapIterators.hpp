/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:26:10 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/26 13:53:59 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATORS_HPP
#define MAPITERATORS_HPP

#include "./extras.hpp"

namespace ft
{

	/* lexicographical compare */

	/*
	** Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2)
	*/
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 )
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	};
}

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
		pair	(const pair<U,V>& other) : first(other.first), second(other.second)
		{}

		pair	(const first_type& a, const second_type& b) : first(a), second(b)
		{}

		pair&	operator=(const pair& other)
		{
			this->first = other.first;
			this->second = other.second;
			return (*this);	
		}

		~pair()
		{}
	};


	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{return (pair<T1,T2>(x,y));}

	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{return (lhs.first == rhs.first && lhs.second == rhs.second);}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{return (lhs.first != rhs.first && lhs.second != rhs.second);}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{return (lhs.first < rhs.first && lhs.second < rhs.second);}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{return (lhs.first <= rhs.first && lhs.second <= rhs.second);}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{return (lhs.first > rhs.first && lhs.second > rhs.second);}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{return (lhs.first >= rhs.first && lhs.second >= rhs.second);}

};

namespace ft
{
	template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
	
	template <class T>
	struct	Node
	{
		T data;
		Node *prev;
		Node *next;
	};


	template <class Key, class T>
	struct	BNode
	{
		pair<Key, T> pair;
		BNode *left;
		BNode *right;
		BNode *parent;
		bool end;
	};
}

namespace ft
{
	template <class K, class T>
	class MapIterator
	{
		public:
			typedef pair<K, T> value_type;
			typedef pair<K, T>& reference;
			typedef BNode<K, T>* pointer;
		protected:
			pointer _ptr;
		private:
			pointer find_next(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			}

			pointer find_prev(pointer ptr)
			{
				pointer next;

				if (!ptr->left)
				{
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return (next);
			}

		public:
			MapIterator(void)
			: _ptr(0)
			{}

			MapIterator(const pointer ptr)
			: _ptr(ptr)
			{}

			MapIterator(const MapIterator &other)
			{
				*this = other;
			}

			MapIterator &operator=(const MapIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			}

			pointer node(void)
			{
				return (_ptr);
			}

			value_type &operator*(void)
			{
				return (_ptr->pair);
			}

			value_type *operator->(void)
			{
				return (&_ptr->pair);
			}

			bool operator==(const MapIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			}

			bool operator!=(const MapIterator<K, T> &other)
			{
				return (!(*this == other));
			}

			bool operator>(const MapIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			}

			bool operator<(const MapIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			}

			bool operator>=(const MapIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			}

			bool operator<=(const MapIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			}

			MapIterator &operator++(void)
			{
				_ptr = find_next(_ptr);
				return (*this);
			}

			MapIterator &operator--(void)
			{
				_ptr = find_prev(_ptr);
				return (*this);
			}

			MapIterator operator++(int)
			{
				MapIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			MapIterator operator--(int)
			{
				MapIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

	};

	template <class K, class T>
	class ReverseMapIterator
	{
		public:
			typedef pair<K, T> value_type;
			typedef pair<K, T>& reference;
			typedef BNode<K, T>* pointer;
		protected:
			pointer _ptr;
		private:
			pointer find_next(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			}

			pointer find_prev(pointer ptr)
			{
				pointer next;

				if (!ptr->left)
				{
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				return (next);
			}

		public:
			ReverseMapIterator(void)
			: _ptr(0)
			{}

			ReverseMapIterator(const pointer ptr)
			: _ptr(ptr)
			{}

			ReverseMapIterator(const ReverseMapIterator &other)
			{
				*this = other;
			}

			ReverseMapIterator &operator=(const ReverseMapIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			}

			pointer node(void)
			{
				return (_ptr);
			}

			value_type &operator*(void)
			{
				return (_ptr->pair);
			}

			value_type *operator->(void)
			{
				return (&_ptr->pair);
			}

			bool operator==(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			}

			bool operator!=(const ReverseMapIterator<K, T> &other)
			{
				return (!(*this == other));
			}

			bool operator>(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			}

			bool operator<(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			}

			bool operator>=(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			}

			bool operator<=(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			}

			ReverseMapIterator &operator++(void)
			{
				_ptr = find_prev(_ptr);
				return (*this);
			}

			ReverseMapIterator &operator--(void)
			{
				_ptr = find_next(_ptr);
				return (*this);
			}

			ReverseMapIterator operator++(int)
			{
				ReverseMapIterator tmp(*this);
				this->operator++();
				return (tmp);
			}

			ReverseMapIterator operator--(int)
			{
				ReverseMapIterator tmp(*this);
				this->operator--();
				return (tmp);
			}

	};

}


#endif