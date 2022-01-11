/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:37:20 by maraurel          #+#    #+#             */
/*   Updated: 2022/01/11 13:46:39 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_HPP
#define EXTRAS_HPP

#include "./includes.hpp"

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

		const
		class nullptr_t
		{
			public:
				template<class T>
				operator T*() const
					{ return 0; }

				template<class C, class T>
				operator T C::*() const
					{ return 0; }

			private:
				void operator&() const;    /* Can't take address of nullptr */

		} nullptr = {}; 

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

	template <class Key, class T>
	class createNode
	{
		public:
			typedef Key 												key_type;
			typedef T													mapped_type;
			typedef BNode<key_type, mapped_type>*						node;
			
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
	};
}

#endif