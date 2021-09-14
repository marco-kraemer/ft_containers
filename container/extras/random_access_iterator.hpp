/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/14 13:41:52 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "../vector.hpp"

namespace ft
{
	template<class T>
	class random_access_iterator
	{
		public:
			typedef	T		value_type;
			typedef T*		pointer;
			typedef T&		reference;
			typedef std::ptrdiff_t	difference_type;

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
			random_access_iterator& operator=(const random_access_iterator& x)
			{
				this->p = x.p;
				return (*this);
			}

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
			random_access_iterator operator++(int)
			{
				random_access_iterator tmp(*this);
			
				operator++();
				return (tmp);
			}

			/*
			** Pre-decrement
			*/
			random_access_iterator& operator--()
			{
				this->p--;
				return (*this);
			}

			/*
			** Post-decremet
			*/
			random_access_iterator operator--(int)
			{
				random_access_iterator tmp(*this);
			
				operator--();
				return (tmp);
			}

			// Arithmetic operators

			random_access_iterator operator+(int n) const
			{
				random_access_iterator tmp(*this);
			
				tmp += n;
				return (tmp);
			}

			random_access_iterator operator-(int n) const
			{
				random_access_iterator tmp(*this);
			
				tmp -= n;
				return (tmp);
			}

			difference_type operator-(random_access_iterator const &other) const
			{
				return (this->p - other.p);
			}

			random_access_iterator& operator+=(int n)
			{
				this->p += n;
				return (*this);
			}

			random_access_iterator& operator-=(int n)
			{
				this->p -= n;
				return (*this);
			}

			// Bool operators
		
			bool operator>(const random_access_iterator &other) const
			{
				return (this->p > other.p);
			}

			bool operator<(const random_access_iterator &other) const
			{
				return (this->p < other.p);
			}

			bool operator>=(const random_access_iterator &other) const
			{
				return (this->p >= other.p);
			}

			bool operator<=(const random_access_iterator &other) const
			{
				return (this->p <= other.p);
			}

			/*
			** Offset dereference operato
			*/
			reference	operator[](int n)const
			{return (*(*this + n));}
			
			
		private:
			pointer	p;
	};	
}

#endif