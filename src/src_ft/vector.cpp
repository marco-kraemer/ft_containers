/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:40:31 by maraurel          #+#    #+#             */
/*   Updated: 2021/12/15 12:53:41 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.hpp"	

void	vec_begin_end()
{
	ft::vector<int> myvector;
	for (int i=1; i<=5; i++)
		myvector.push_back(i);

	std::cout << "myvector contains:";
	for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	vec_size()
{
	ft::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(), (size_t)10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}

void	vec_max_size()
{
	ft::vector<int> myvector;

	for (int i=0; i<100; i++) 
		myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}

void	vec_resize()
{
	ft::vector<int> myvector;

	// set some initial content:
	for (int i = 1; i < 10; i++)
		myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (int i = 0; i < (int)myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	vec_capacity()
{
	ft::vector<char> myvector;

	for (int i = 0; i < 100; i++)
		myvector.push_back('a');

	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector.max_size() << '\n';
}

void	vec_empty()
{
	ft::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++)
		myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total: " << sum << '\n';
}

void	vec_reserve()
{
	ft::vector<int>::size_type sz;

	ft::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
			foo.push_back(i);
		if (sz!=foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	ft::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		if (sz!=bar.capacity())
		{
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void	vec_operator()
{
	ft::vector<int> myvector (10);
	
	ft::vector<int>::size_type sz = myvector.size();

	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	for (unsigned i = 0; i < sz / 2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	vec_at()
{
	ft::vector<int> myvector (10);

	for (unsigned i = 0; i < myvector.size(); i++)
		myvector.at(i) = i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
	std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
}

void	vec_front()
{
	ft::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
}

void	vec_back()
{
	ft::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	vec_assign()
{
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign ((size_t)7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
}

void	vec_push_back()
{
	ft::vector<int> myvector;


	for (int i = 0; i < 100; i++)
		myvector.push_back(i);

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
}

void	vec_pop_back()
{
	ft::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
}

void	vec_insert()
{
	ft::vector<int> myvector (3, (size_t)100);
	ft::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it, (size_t)2, 300);

	it = myvector.begin();

	ft::vector<int> anothervector (2, (size_t)400);
	myvector.insert (it + 2, anothervector.begin(), anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	vec_erase()
{
	ft::vector<int> myvector;

	for (int i=1; i<=10; i++) myvector.push_back(i);

	myvector.erase (myvector.begin()+5);

	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
	std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	vec_swap()
{
	ft::vector<int> foo (3, (size_t)100);   // three ints with a value of 100
	ft::vector<int> bar (5, (size_t)200);   // five ints with a value of 200

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
}

void	vec_clear()
{
	ft::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

void	vec_get_allocator()
{
	ft::vector<int> myvector;
	int * p;
	unsigned int i;

	p = myvector.get_allocator().allocate(5);

	for (i = 0; i < 5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++)
		std::cout << ' ' << p[i];
	std::cout << '\n';

	for (i = 0; i < 5; i++)
		myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void	vec_rbegin_rend()
{
	ft::vector<int> myvector (5);  // 5 default-constructed ints

	ft::vector<int>::reverse_iterator rit = myvector.rbegin();

	int i = 0;
	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (ft::vector<int>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	vec_assignation_test()
{
	ft::vector<int> foo;
	for (int i = 0; i < 25; ++i) {
			foo.push_back(i);
	}
	std::cout << "Main container:" << std::endl;
	ft::vector<int>::iterator it = foo.begin();
	for (; it != foo.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
	ft::vector<int> bar;
	bar = foo;
	ft::vector<int>::iterator it2 = bar.begin();
	std::cout << "\n\nCopy container:" << std::endl;
	for (; it2 != bar.end(); it2++) {
		std::cout << *it2 << ", ";
	}
	std::cout << "\n\nChange copy container element 10 (Deep copy test) \n" << std::endl;
	bar[10] = 99999;
	std::cout << "Main container:" << std::endl;
	for (it = foo.begin(); it != foo.end(); it++) {
		std::cout << *it << ", ";
	}
	std::cout << "\n\nCopy container:" << std::endl;
	for (it2 = bar.begin(); it2 != bar.end(); it2++) {
		std::cout << *it2 << ", ";
	}	
}

void	vec_iterator_compare()
{
	ft::vector<int> foo;
	for (int i = 0; i < 25; ++i) {
			foo.push_back(i);
	}
	ft::vector<int>::iterator it1 = foo.begin();
	ft::vector<int>::const_iterator it2 = foo.begin();
	if (it1 == it2) {
		std::cout << "iterator and const iterator are equal" << std::endl;
	}
	else {
		std::cout << "Iterator and const iterator are different" << std::endl;
	}
}

void	vector_tests()
{
	std::cout << "\n------------------------------ TESTING VECTOR CONTAINER ----------------------------------------------" << std::endl;

	std::cout << "\n\nCompare iterator and const iterator \n" << std::endl;
	vec_iterator_compare();
	std::cout << "\n\nVector test assignation \n" << std::endl;
	vec_assignation_test();
	std::cout << "\n\nVector test swap() \n" << std::endl;
	vec_swap();
	std::cout << "\n\nVector test begin() and end() \n" << std::endl;
	vec_begin_end();
	std::cout << "\n\nVector test rbegin() and rend() \n" << std::endl;
	vec_rbegin_rend();
	std::cout << "\n\nVector test size() \n" << std::endl;
	vec_size();
	std::cout << "\n\nVector test max_size() \n" << std::endl;
	vec_max_size();
	std::cout << "\n\nVector test resize() \n" << std::endl;
	vec_resize();
	std::cout << "\n\nVector test capacity() \n" << std::endl;
	vec_capacity();	
	std::cout << "\n\nVector test empty() \n" << std::endl;
	vec_empty();
	std::cout << "\n\nVector test reserve() \n" << std::endl;
	vec_reserve();
	std::cout << "\n\nVector test operator [] \n" << std::endl;
	vec_operator();
	std::cout << "\n\nVector test at() \n" << std::endl;
	vec_at();
	std::cout << "\n\nVector test front() \n" << std::endl;
	vec_front();
	std::cout << "\n\nVector test back() \n" << std::endl;
	vec_back();
	std::cout << "\n\nVector test assign() \n" << std::endl;
	vec_assign();
	std::cout << "\n\nVector test push_back() \n" << std::endl;
	vec_push_back();
	std::cout << "\n\nVector test pop_back() \n" << std::endl;
	vec_pop_back();
	std::cout << "\n\nVector test insert() \n" << std::endl;
	vec_insert();
	std::cout << "\n\nVector test erase() \n" << std::endl;
	vec_erase();
	std::cout << "\n\nVector test clear() \n" << std::endl;
	vec_clear();
	std::cout << "\n\nVector test get_allocator() \n" << std::endl;
	vec_get_allocator();
}