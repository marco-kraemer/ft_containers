/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterators.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 17:26:10 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/26 14:51:04 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATORS_HPP
#define MAPITERATORS_HPP

#include "./includes.hpp"

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