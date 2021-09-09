/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:21:21 by user42            #+#    #+#             */
/*   Updated: 2021/09/09 09:44:52 by user42           ###   ########.fr       */
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
			typedef T	value_type;
			typedef Alloc	allocator_type;
			typedef T*	pointer;
			typedef T&	reference;

			explicit vector (const allocator_type& alloc = allocator_type()) :
				_first(nullptr),
				_last(nullptr),
				_end_capacity(nullptr),
				_alloc(alloc) 
			{}

		private:
			pointer		_first;
			pointer		_last;
			pointer		_end_capacity;
			allocator_type	_alloc;
	};
}

#endif