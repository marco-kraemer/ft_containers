/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:37:20 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/17 15:14:56 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRAS_HPP
#define EXTRAS_HPP

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
		pair (const pair<U,V>& pr); first(pr.first), second(pr.second)
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
		return (lsh.first == rsh.first && lsh.second == rsh.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lsh.first != rsh.first && lsh.second != rsh.second);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lsh.first < rsh.first && lsh.second < rsh.second);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lsh.first <= rsh.first && lsh.second <= rsh.second);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lsh.first > rsh.first && lsh.second > rsh.second);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lsh.first >= rsh.first && lsh.second >= rsh.second);
	}
}

#endif