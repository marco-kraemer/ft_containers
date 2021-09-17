/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:12:00 by maraurel          #+#    #+#             */
/*   Updated: 2021/09/17 15:03:19 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

# include <iostream>
# include <vector>
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>

# include "extras/random_access_iterator.hpp"
# include "extras/extras.hpp"

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
	
	class map
	{
		typedef Key					key_type;
		typedef T					mapped_type;
		typedef ft::pair<const key_type, mapped_type>	key_compare;
		typedef Compare					value_compare;
		typedef Alloc					allocator_type;
		typedef allocator_type::reference		reference;
		typedef allocator_type::const_reference		const_reference;
		typedef allocator_type::pointer			const_pointer;
		typedef allocator_type::const_pointer		const_pointer;
		typedef size_t					size_type;
	};
}

#endif