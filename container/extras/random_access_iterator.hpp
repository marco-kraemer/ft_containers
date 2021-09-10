/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/10 11:54:32 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "../vector.hpp"

namespace ft
{
	template<typename T>
	class random_access_iterator : public T
	{
		public:
			typedef	T	value_type;
			typedef T*	pointer;
			typedef T&	reference;

			/*
			** Default constructor
			*/
			random_access_iterator() : p(nullptr)
			{}

			/*
			** Copy constructor
			*/
			random_access_iterator(const random_access_iterator& x) : p(x.p)
			{}

			/*
			** Pointer constructor
			*/
			random_access_iterator(pointer p) : p(p)
			{}

			/*
			** Operator =
			*/
			random_access_iterator& operator= (const random_access_iterator& x)
			{return (*this);}

			/*
			** destructor
			*/
			virtual ~random_access_iterator()
			{}

			/*
			** Equality operator
			*/
			bool	operator==(const random_access_iterator& x)
			{return (this->p = x.p);}

			/*
			** Inequality operator
			*/
			bool	operator!=(const random_access_iterator& x)
			{return (this->p != x.p);}

			/*
			** Dereferenced as an rvalue
			*/
			reference	operator*(void)
			{return (*this->p);}

			pointer		operator->(void)
			{return (this->p);}

			/*
			** Pre-increment
			*/
			random_access_iterator& operator++()
			{
				this->p++;
				return (*this);
			}

			/*
			** Post-increment
			*/
			random_access_iterator& operator++(int)
			{
				random_access_iterator tmp(*this);
			
				operator++();
				return (tmp);
			}

		private:
			pointer	p;
	};	
}

#endif