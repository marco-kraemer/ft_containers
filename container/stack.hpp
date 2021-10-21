/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:01:36 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/21 15:22:28 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

# include "extras/extras.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		public:
			typedef T		value_type;

			typedef	Container	container_type;
		
			typedef size_t		size_type;


		protected:
			container_type	_container;

		public:
			/* Constructors and desctructor */
			
			/*
			** Constructs a stack container adaptor object.
			*/
			explicit stack (const container_type& ctnr = container_type()) : _container(ctnr)
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
				this->_container = other._container;
				return (*this);
			}

			/*
			** Constructs a map container object, initializing its contents depending on the constructor version used:
			** Copy version
			*/
			stack(const stack &other)
			{*this = other;}
	};
}

#endif