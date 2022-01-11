/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:50:03 by maraurel          #+#    #+#             */
/*   Updated: 2021/12/15 12:46:08 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

# include "extras/includes.hpp"

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{	
		public:
			typedef T									value_type;
		
			typedef Alloc								allocator_type;
		
			typedef T*									pointer;
		
			typedef T&									reference;
		
			typedef const T&							const_reference;
		
			typedef typename allocator_type::size_type	size_type;
		
			typedef VectorIterator<T>					iterator;
		
			typedef const VectorIterator<T>				const_iterator;

			typedef ReverseVectorIterator<T>			reverse_iterator;

			typedef const ReverseVectorIterator<T>		const_reverse_iterator;


			// Constructors

			/*
			** Empty container constructor (default constructor)
			** Constructs an empty container, with no elements.
			*/
			explicit vector (const allocator_type& alloc = allocator_type()) :
				_first(nullptr),
				_last(nullptr),
				_capacity(nullptr),
				_alloc(alloc) 
			{}

			/*
			** Fill constructor
			** Constructs a container with n elements. Each element is a copy of val.
			*/
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) :
				_first(nullptr),
				_last(nullptr),
				_capacity(nullptr),
				_alloc(alloc) 
			{
				_first = _alloc.allocate(n);
				_capacity = _first + n;
				_last = _first;
				for (int length = 0; length < (int)n; length++)
				{
					_alloc.construct(_last, val);
					_last++;
				}
			}

			/*
			** Range constructor
			** Constructs a container with as many elements as the range [first,last),
			** with each element constructed from its corresponding element in that range, in the same order.
			*/
			template<class InputIterator>
			int distance (InputIterator first, InputIterator last)
			{
				iterator rtn = 0;
				while (first != last)
				{
				first++;
				rtn++;
				}
				return (rtn);
			}

			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type()) :
				_alloc(alloc)
			{
				insert(begin(), first, last);
			}

			/*
			** Copy constructor
			** Constructs a container with a copy of each of the elements in x, in the same order.
			*/
			vector (const vector& x) :
			_first(nullptr),
			_last(nullptr),
			_capacity(nullptr),
			_alloc(x._alloc) 
			{
				this->insert(this->begin(), x.begin(), x.end());
			}

			// Destructors
			
			/*
			** This destroys all container elements,
			** and deallocates all the storage capacity allocated by the vector using its allocator.
			*/
			~vector()
			{
				_alloc.deallocate(_first, this->capacity());
			}

			// Operator =

			/*
			** Assigns new contents to the container,
			** replacing its current contents, and modifying its size accordingly.
			*/
			vector& operator= (const vector& x)
			{
				this->insert(this->begin(), x.begin(), x.end());
				return (*this);
			}

			// Iterators

			/*
			** Returns an iterator pointing to the first element in the vector.
			** If the container is empty, the returned iterator value shall not be dereferenced.
			*/
			iterator begin()
			{return (this->_first);}

			/*
			** Returns an iterator pointing to the first element in the vector.
			** If the container is empty, the returned iterator value shall not be dereferenced.
			*/
			const_iterator begin() const
			{return (this->_first);}

			/*
			** Returns an iterator referring to the past-the-end element in the vector container.
			** If the container is empty, this function returns the same as vector::begin.
			*/
			iterator end()
			{
				if (this->empty())
					return (this->begin());
				return (this->_last);
			}

			/*
			** Returns an iterator referring to the past-the-end element in the vector container.
			** If the container is empty, this function returns the same as vector::begin.
			*/
			const_iterator end() const
			{
				if (this->empty())
					return (this->begin());
				return (this->_last);
			}


			/*
			** Returns a reverse iterator pointing to the first element in the vector.
			** If the container is empty, the returned reverse iterator value shall not be dereferenced.
			*/
			reverse_iterator rbegin()
			{return (this->_last);}

			/*
			** Returns a reverse iterator pointing to the first element in the vector.
			** If the container is empty, the returned reverse iterator value shall not be dereferenced.
			*/
			const_reverse_iterator rbegin() const
			{return (this->_last);}

			/*
			** Returns a reverse iterator referring to the past-the-end element in the vector container.
			** If the container is empty, this function returns the same as vector::begin.
			*/
			reverse_iterator rend()
			{return (this->_first);}

			/*
			** Returns a reverse iterator referring to the past-the-end element in the vector container.
			** If the container is empty, this function returns the same as vector::begin.
			*/
			const_reverse_iterator rend() const
			{return (this->_first);}

			// Capacity

			/*
			** Returns the number of elements in the vector.
			*/
			size_type size() const
			{return (_last - _first);}

			/*
			** Returns the maximum number of elements that the vector can hold.
			** This is the maximum potential size the container can reach due to known system
			** or library implementation limitations
			*/
			size_type max_size() const
			{return (allocator_type().max_size());}

			/*
			** Resizes the container so that it contains n elements.
			** If n is smaller than the current container size, the content is reduced to its first n elements,
			** removing those beyond (and destroying them).
			** If n is greater than the current container size,
			** the content is expanded by inserting at the end as many elements as needed to reach a size of n.
			** Notice that this function changes the actual content of the container by inserting or erasing elements from it.
			*/
			void resize (size_type n, value_type val = value_type())
			{
				int i = 0;
				
				if (!val)
					val = 0;
				pointer new_last = pointer();
				if (n < this->size())
				{
					new_last = this->_first;
					while (i < (int)n)
					{
						i++;
						new_last++;
					}
					this->_last = new_last;
					while (i < (int)this->size())
					{
						_alloc.deallocate(new_last, val);
						new_last++;
						i++;
					}			
				}
				else
					insert(this->end(), n - this->size(), val);
			}

			/*
			** Returns the size of the storage space currently allocated for the vector,
			** expressed in terms of elements.
			** This capacity is not necessarily equal to the vector size. It can be equal or greater,
			** with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
			*/
			size_type capacity() const
			{return (this->_capacity - this->_first);}	

			/*
			** Returns whether the vector is empty (i.e. whether its size is 0).
			** This function does not modify the container in any way.
			** To clear the content of a vector, see vector::clear.
			*/
			bool empty() const
			{
				if (this->size() == 0)
					return (true);
				return (false);
			}

			/*
			** Requests that the vector capacity be at least enough to contain n elements.
			** If n is greater than the current vector capacity,
			** the function causes the container to reallocate its storage increasing its capacity to n (or greater).
			** In all other cases, the function call does not cause a reallocation
			** and the vector capacity is not affected.
			*/
			void reserve (size_type n)
			{
				pointer		old_first = _first;
				pointer		old_last = _last;
				size_type	old_size = this->size();
				size_type	old_capacity = this->capacity();

				_first = _alloc.allocate(n);
				_last = _first;
				_capacity = _first + n;
				while (old_first != old_last)
				{
					_alloc.construct(_last, *old_first);
					_last++;
					old_first++;
				}
				_alloc.deallocate(old_first - old_size, old_capacity);
			}

			// Element Access

			/*
			** Returns a reference to the element at position n in the vector container.
			*/
			reference operator[] (size_type n)
			{return (*(_first + n));}

			/*
			** Returns a reference to the element at position n in the vector.
			** This is in contrast with member operator[], that does not check against bounds.
			*/
			reference at (size_type n)
			{
				if (n > this->size())
					throw std::out_of_range("Out of range");
				return (*(_first + n));
			}

			/*
			** Returns a reference to the element at position n in the vector.
			** This is in contrast with member operator[], that does not check against bounds.
			*/
			const_reference at (size_type n) const
			{
				if (n > this->size())
					throw std::out_of_range("Out of range");
				return (*(_first + n));
			}
			
			/*
			** Returns a reference to the first element in the vector.
			** Unlike member vector::begin, which returns an iterator to this same element,
			** this function returns a direct reference.
			*/
			reference front()
			{return (*_first);}

			/*
			** Returns a reference to the first element in the vector.
			** Unlike member vector::begin, which returns an iterator to this same element,
			** this function returns a direct reference.
			*/
			const_reference front() const
			{return (*_first);}

			/*
			** Returns a reference to the last element in the vector.
			** Unlike member vector::end, which returns an iterator just past this element,
			** this function returns a direct reference.
			*/
			reference back()
			{return (*(_last - 1));}

			/*
			** Returns a reference to the last element in the vector.
			** Unlike member vector::end, which returns an iterator just past this element,
			** this function returns a direct reference.
			*/
			const_reference back() const
			{return (*(_last - 1));}
			
			// Modifiers

			/*
			** Assigns new contents to the vector, replacing its current contents,
			** and modifying its size accordingly.
			*/
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				size_type dist    = last - first;
			
				if (this->capacity() >= dist)
				{
					for (; &(*first) != &(*last); first++, _last++)
						_alloc.construct(_last, *first);
				}
				else
				{
					pointer new_first    = pointer();
					pointer new_last     = pointer();
					pointer new_capacity = pointer();

					new_first    = _alloc.allocate(dist);
					new_last     = new_first;
					new_capacity = new_first + dist;
					
					while (&(*first) != &(*last))
					{
						_alloc.construct(new_last, *first);
						first++;
						new_last++;
					}
					_alloc.deallocate(_first, this->capacity());
					_first    = new_first;
					_last     = new_last;
					_capacity = new_capacity;
				}
			}

			/*
			** Assigns new contents to the vector, replacing its current contents,
			** and modifying its size accordingly.
			*/
			void assign (size_type n, const_reference val)
			{
				if (n > this->capacity())
				{
					_alloc.deallocate(_first, this->capacity());
					_first = _alloc.allocate(n);
				}
				_last = _first;
				_capacity = _first + n;
				for (; this->size() < n;_last++)
					_alloc.construct(_last, val);
			}

			/*
			** Adds a new element at the end of the vector, after its current last element.
			** The content of val is copied (or moved) to the new element.
			*/		
			void push_back (const value_type& val)
			{
				if (_last == _capacity)
				{
					int	new_capacity;
	
					if (size() == 0)
						new_capacity = 1;
					else
						new_capacity = (this->size() * 2);
					this->reserve(new_capacity);
				}
				_alloc.construct(_last, val);
				_last++;
			}

			/*
			** Removes the last element in the vector, effectively reducing the container size by one.
			** This destroys the removed element.
			*/
			void pop_back()
			{
				pointer	old_last = _last;
				old_last--;
				_alloc.destroy(_last);
				_last = old_last;
			}

			/*
			** The vector is extended by inserting new elements before the element at the specified position,
			** effectively increasing the container size by the number of elements inserted.
			** This causes an automatic reallocation of the allocated storage.
			*/		
			iterator insert (iterator position, const value_type& val)
			{
				size_type len = &(*position) - _first;

				if (size_type(_capacity - _last) >= this->size() + 1)
				{
					for (size_type i = 0; i < len; i++)
						_alloc.construct(_last - i, *(_last - i - 1));
					_last++;
					_alloc.construct(&(*position), val);
				}
				else
				{
					int next_capacity;
					if (this->size() * 2 > 0)
						next_capacity = this->size() * 2;
					else
						next_capacity = 1;

					pointer new_first = pointer();
					pointer new_last = pointer();
					pointer new_capacity = pointer();

				
					new_first = _alloc.allocate(next_capacity);
					new_last = new_first + this->size() + 1;
					new_capacity = new_first + next_capacity;

					for (size_type i = 0; i < len; i++)
						_alloc.construct(new_first + i, *(_first + i));
					_alloc.construct(new_first + len, val);
					for (size_type j = 0; j < this->size() - len; j++)
						_alloc.construct(new_last - j - 1, *(_last - j - 1));

					for (size_type l = 0; l < this->size(); l++)
						_alloc.destroy(_first + l);

					if (_first)
						_alloc.deallocate(_first, this->capacity());

					_first = new_first;
					_last = new_last;
					_capacity = new_capacity;					
				}
				return (iterator(_first + len));
			}

			/*
			** The vector is extended by inserting new elements before the element at the specified position,
			** effectively increasing the container size by the number of elements inserted.
			** This causes an automatic reallocation of the allocated storage.
			*/			
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type len = &(*position) - _first;
				size_type size = n;
				
				if (size_type(_capacity - _last) >= n)
				{
					for (size_type i = 0; i < this->size() - len; i++)
						_alloc.construct(_last - i + (n - 1), *(_last - i - 1));
					_last += n;
					while (n)
					{
						_alloc.construct(&(*position) + (n - 1), val);
						n--;
					}
				}
				else
				{
					int next_capacity;
					if (this->size() * 2 > 0)
						next_capacity = this->size() * 2;
					else
						next_capacity = 1;
				
					pointer new_first = pointer();
					pointer new_last = pointer();
					pointer new_capacity = pointer();

					new_first = _alloc.allocate(next_capacity);
					new_capacity = new_first + next_capacity;

					if (size_type(new_capacity - new_first) < this->size() + size)
					{
						if (new_first)
							_alloc.deallocate(new_first, new_first - new_capacity);
						new_first = _alloc.allocate(this->size() + size);
						new_last = new_first + this->size() + size;
						new_capacity = new_first + (this->size() + size);
					}
					
					new_last = new_first + this->size() + size;
					
					for (int i = 0; i < &(*position) - _first; i++)
						_alloc.construct(new_first + i, *(_first + i));
					for (size_type j = 0; j < n; j++)
						_alloc.construct(new_first + len + j, val);
					for (size_type j = 0; j < (this->size() - len); j++)
						_alloc.construct(new_last - j - 1, *(_last - j - 1));
						
					for (size_type l = 0; l < this->size(); l++)
						_alloc.destroy(_first + l);
					_alloc.deallocate(_first, this->capacity());

					_first = new_first;
					_last = new_last;
					_capacity = new_capacity;
				}
			}

			/*
			** The vector is extended by inserting new elements before the element at the specified position,
			** effectively increasing the container size by the number of elements inserted.
			** This causes an automatic reallocation of the allocated storage.
			*/
			template <class InputIterator>
				void insert (iterator position, InputIterator first, InputIterator last)
			{
				size_type size = last - first;
				if (size_type(_capacity - _last) >= size)
				{
					for (size_type i = 0; i < this->size() - (&(*position) - _first); i++)
						_alloc.construct(_last - i + (size - 1), *(_last - i -1));
					_last += size;
					for (; &(*first) != &(*last); first++, position++)
						_alloc.construct(&(*position), *first);
				}
				else
				{
					pointer new_first = pointer();
					pointer new_last = pointer();
					pointer new_capacity = pointer();

					new_first = _alloc.allocate(this->size() * 2);
					new_last = new_first + this->size() + size;
					new_capacity = new_first + (this->size() * 2);

					if (size_type(new_capacity - new_first) < this->size() + size)
					{
						if (new_first)
							_alloc.deallocate(new_first, new_capacity - new_first);
						new_first = _alloc.allocate(this->size() + size);
						new_last = new_first + this->size() + size;
						new_capacity = new_last;
					}
					for (int i = 0; i < &(*position) - _first; i++)
						_alloc.construct(new_first + i, *(_first + i));
					for (int j = 0; &(*first) != &(*last); first++, j++)
						_alloc.construct(new_first + (&(*position) - _first) + j, *first);
					for (size_type k = 0; k < this->size() - (&(*position) - _first); k++)
						_alloc.construct(new_first + (&(*position) - _first) + size + k, *(_first + (&(*position) - _first) + k));

					for (size_type l = 0; l < this->size(); l++)
						_alloc.destroy(_first + l);
					_alloc.deallocate(_first, this->capacity());

					_first = new_first;
					_last = new_last;
					_capacity = new_capacity;
				}
			}

			/*
			** Removes from the vector a single element(position).
			** This effectively reduces the container size by the number of elements removed, which are destroyed.
			*/
			iterator erase (iterator position)
			{
				if (&(*position) + 1 == _last)
					_alloc.destroy(&(*position));
				else
				{
					for (int i = 0; i < _last - &(*position) - 1; i++)
					{
						_alloc.construct(&(*position) + i, *(&(*position) + i + 1));
						_alloc.destroy(&(*position) + i + 1);
					}
				}
				_last--;
				return (iterator(position));
			}

			/*
			** Removes from the vector a single element(position).
			** This effectively reduces the container size by the number of elements removed, which are destroyed.
			*/
			iterator erase (iterator first, iterator last)
			{
				pointer	new_first = &(*first);
				
				while (&(*first) != &(*last))
				{
					_alloc.destroy(&(*first));
					first++;
				}
				for (int i = 0; i < _last - &(*last); i++)
				{
					_alloc.construct(new_first + i, *(&(*last) + i));
					_alloc.destroy(&(*last) + i);
				}
				_last -= (&(*last) - new_first);
				return (iterator(new_first));
			}

			/*
			** Exchanges the content of the container by the content of x,
			** which is another vector object of the same type. Sizes may differ.
			*/
			void swap (vector& x)
			{
				pointer tmp_first		= this->_first;
				pointer	tmp_last		= this->_last;
				pointer tmp_capacity		= this->_capacity;
				allocator_type tmp_alloc	= this->_alloc;
			
				this->_first	= x._first;
				this->_last 	= x._last;
				this->_capacity	= x._capacity;
				this->_alloc	= x._alloc;
	
				x._first	= tmp_first;
				x._last		= tmp_last;
				x._capacity	= tmp_capacity;
				x._alloc	= tmp_alloc;
			}

			/*
			** Removes all elements from the vector (which are destroyed),
			** leaving the container with a size of 0.
			*/
			void clear()
			{
				while (_last != _first)
				{
					_alloc.destroy(_last);
					_last--;
				}
			}

			// Allocator
	
			/*
			** Returns a copy of the allocator object associated with the vector.
			*/
			allocator_type get_allocator() const
			{return (this->_alloc);}

		private:
			pointer		_first;
			pointer		_last;
			pointer		_capacity;
			allocator_type	_alloc;
	};
	
	/*
	** The contents of container x are exchanged with those of y.
	** Both container objects must be of the same type (same template parameters), although sizes may differ.
	*/
	template <class T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{x.swap(y);}

	/*
	** Performs the appropriate comparison operation between the vector containers lhs and rhs.
	*/
	template <class T, class Alloc>
		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		int	i;

		if (lhs.size() != rhs.size())
			return (false);
		i = 0;
		while (i < lhs.size())
		{
			if (rhs[i] != lhs[i])
				return (false);
			i++;
		}
		return (true);
	}

	/*
	** Performs the appropriate comparison operation between the vector containers lhs and rhs.
	*/
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		int	i;

		if (lhs.size() != rhs.size())
			return (true);
		i = 0;
		while (i < lhs.size())
		{
			if (rhs[i] != lhs[i])
				return (true);
			i++;
		}
		return (false);	
	}

	/*
	** Performs the appropriate comparison operation between the vector containers lhs and rhs.
	*/
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));}

	/*
	** Performs the appropriate comparison operation between the vector containers lhs and rhs.
	*/
	template <class T, class Alloc>
	bool operator<=  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return (!(rhs < lhs));}

	/*
	** Performs the appropriate comparison operation between the vector containers lhs and rhs.
	*/
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return (rhs < lhs);}

	/*
	** Performs the appropriate comparison operation between the vector containers lhs and rhs.
	*/
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return (!(lhs < rhs));}
}

#endif