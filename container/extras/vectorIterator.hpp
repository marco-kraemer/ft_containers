/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 09:23:25 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/26 13:46:03 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITEARATOR_HPP
# define VECTORITEARATOR_HPP

#include "extras.hpp"

namespace ft
{
	template<class T>
	class VectorIterator
	{
		public:
			typedef	T		value_type;
			typedef T*		pointer;
			typedef T&		reference;
			typedef std::ptrdiff_t	difference_type;

			/*
			** Default constructor
			*/
			VectorIterator() : p(nullptr)
			{}

			/*
			** Copy constructor
			*/
			VectorIterator(const VectorIterator& x) : p(x.p)
			{}

			/*
			** Pointer constructor
			*/
			VectorIterator(pointer p) : p(p)
			{}

			/*
			** Operator =
			*/
			VectorIterator& operator=(const VectorIterator& x)
			{
				this->p = x.p;
				return (*this);
			}

			/*
			** destructor
			*/
			virtual ~VectorIterator()
			{}

			/*
			** Equality operator
			*/
			bool	operator==(const VectorIterator& x)
			{return (this->p = x.p);}

			/*
			** Inequality operator
			*/
			bool	operator!=(const VectorIterator& x)
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
			VectorIterator& operator++()
			{
				this->p++;
				return (*this);
			}

			/*
			** Post-increment
			*/
			VectorIterator operator++(int)
			{
				VectorIterator tmp(*this);
			
				operator++();
				return (tmp);
			}

			/*
			** Pre-decrement
			*/
			VectorIterator& operator--()
			{
				this->p--;
				return (*this);
			}

			/*
			** Post-decremet
			*/
			VectorIterator operator--(int)
			{
				VectorIterator tmp(*this);
			
				operator--();
				return (tmp);
			}

			// Arithmetic operators

			VectorIterator operator+(int n) const
			{
				VectorIterator tmp(*this);
			
				tmp += n;
				return (tmp);
			}

			VectorIterator operator-(int n) const
			{
				VectorIterator tmp(*this);
			
				tmp -= n;
				return (tmp);
			}

			difference_type operator-(VectorIterator const &other) const
			{
				return (this->p - other.p);
			}

			VectorIterator& operator+=(int n)
			{
				this->p += n;
				return (*this);
			}

			VectorIterator& operator-=(int n)
			{
				this->p -= n;
				return (*this);
			}

			// Bool operators
		
			bool operator>(const VectorIterator &other) const
			{
				return (this->p > other.p);
			}

			bool operator<(const VectorIterator &other) const
			{
				return (this->p < other.p);
			}

			bool operator>=(const VectorIterator &other) const
			{
				return (this->p >= other.p);
			}

			bool operator<=(const VectorIterator &other) const
			{
				return (this->p <= other.p);
			}

			/*
			** Offset dereference operator
			*/
			reference	operator[](int n)const
			{return (*(*this + n));}
			
			
		private:
			pointer	p;
	};

	template<class T>
	class ReverseVectorIterator
	{
		public:
			typedef	T		value_type;
			typedef T*		pointer;
			typedef T&		reference;
			typedef std::ptrdiff_t	difference_type;

			/*
			** Default constructor
			*/
			ReverseVectorIterator() : p(nullptr)
			{}

			/*
			** Copy constructor
			*/
			ReverseVectorIterator(const ReverseVectorIterator& x) : p(x.p)
			{}

			/*
			** Pointer constructor
			*/
			ReverseVectorIterator(pointer p) : p(p)
			{}

			/*
			** Operator =
			*/
			ReverseVectorIterator& operator=(const ReverseVectorIterator& x)
			{
				this->p = x.p;
				return (*this);
			}

			/*
			** destructor
			*/
			virtual ~ReverseVectorIterator()
			{}

			/*
			** Equality operator
			*/
			bool	operator==(const ReverseVectorIterator& x)
			{return (this->p = x.p);}

			/*
			** Inequality operator
			*/
			bool	operator!=(const ReverseVectorIterator& x)
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
			ReverseVectorIterator& operator++()
			{
				this->p--;
				return (*this);
			}

			/*
			** Post-increment
			*/
			ReverseVectorIterator operator++(int)
			{
				ReverseVectorIterator tmp(*this);
			
				operator++();
				return (tmp);
			}

			/*
			** Pre-decrement
			*/
			ReverseVectorIterator& operator--()
			{
				this->p++;
				return (*this);
			}

			/*
			** Post-decremet
			*/
			ReverseVectorIterator operator--(int)
			{
				ReverseVectorIterator tmp(*this);
			
				operator--();
				return (tmp);
			}

			// Arithmetic operators

			ReverseVectorIterator operator+(int n) const
			{
				ReverseVectorIterator tmp(*this);
			
				tmp -= n;
				return (tmp);
			}

			ReverseVectorIterator operator-(int n) const
			{
				ReverseVectorIterator tmp(*this);
			
				tmp += n;
				return (tmp);
			}

			difference_type operator-(ReverseVectorIterator const &other) const
			{
				return (this->p - other.p);
			}

			ReverseVectorIterator& operator+=(int n)
			{
				this->p -= n;
				return (*this);
			}

			ReverseVectorIterator& operator-=(int n)
			{
				this->p += n;
				return (*this);
			}

			// Bool operators
		
			bool operator>(const ReverseVectorIterator &other) const
			{
				return (this->p > other.p);
			}

			bool operator<(const ReverseVectorIterator &other) const
			{
				return (this->p < other.p);
			}

			bool operator>=(const ReverseVectorIterator &other) const
			{
				return (this->p >= other.p);
			}

			bool operator<=(const ReverseVectorIterator &other) const
			{
				return (this->p <= other.p);
			}

			/*
			** Offset dereference operator
			*/
			reference	operator[](int n)const
			{return (*(*this + n));}
			
			
		private:
			pointer	p;
	};
}

#endif