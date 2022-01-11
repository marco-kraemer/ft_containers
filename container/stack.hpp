/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:01:36 by maraurel          #+#    #+#             */
/*   Updated: 2022/01/11 16:31:51 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef stack_HPP
#define stack_HPP

# include "extras/includes.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T		value_type;

			typedef	Container	container_type;
		
			typedef size_t		size_type;


		protected:
			container_type	c;

		public:
			/* Constructors and desctructor */
			
			/*
			** Constructs a stack container adaptor object.
			*/
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr)
			{}

			/*
			** Destroy a stack container adaptor object.
			*/
			~stack()
			{}

			/*
			** Assigns new contents to the container, replacing its current content.
			*/
			stack &operator=(const stack &other)
			{
				this->c = other.c;
				return (*this);
			}

			/*
			** Constructs a map container object, initializing its contents depending on the constructor version used:
			** Copy version
			*/
			stack(const stack &other)
			{*this = other;}

			/*
			** Returns whether the stack is empty: i.e. whether its size is zero.
			** This member function effectively calls member empty of the underlying container object.
			*/
			bool empty() const
			{return (this->c.empty());}

			/*
			** Returns the number of elements in the stack.
			** This member function effectively calls member size of the underlying container object.
			*/
			size_type size() const
			{return (this->c.size());}

			/*
			** Returns a reference to the top element in the stack.
			** Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.
			** This member function effectively calls member back of the underlying container object.
			*/
			value_type& top()
			{return (this->c.back());}

			/*
			** Returns a const reference to the top element in the stack.
			** Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.
			** This member function effectively calls member back of the underlying container object.
			*/	
			const value_type& top() const
			{return (this->c.back());}

			/*
			** Inserts a new element at the top of the stack, above its current top element.
			** The content of this new element is initialized to a copy of val.
			** This member function effectively calls the member function push_back of the underlying container object.
			*/
			void push (const value_type& val)
			{return (this->c.push_back(val));}

			/*
			** Removes the element on top of the stack, effectively reducing its size by one.
			** The element removed is the latest element inserted into the stack,
			** whose value can be retrieved by calling member stack::top.
			** This member function effectively calls the member function pop_back of the underlying container object.
			*/
			void pop()
			{return (this->c.pop_back());}
	
	};
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{return (lhs.c == rhs.c);};
	
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{return (lhs.c != rhs.c);};
	
	template <class T, class Container>
	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{return (lhs.c > rhs.c);};

	template <class T, class Container>
	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{return (lhs.c < rhs.c);};

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{return (lhs.c >= rhs.c);};

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{return (lhs.c <= rhs.c);};
}

#endif