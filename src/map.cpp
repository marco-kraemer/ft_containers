/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraurel <maraurel@student.42sp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:45:12 by maraurel          #+#    #+#             */
/*   Updated: 2021/10/25 14:33:29 by maraurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../container/extras/extras.hpp"

using namespace ft;

void	map_begin_end()
{
	map<char,int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	map_rbegin_rend()
{
	map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	// show content:
	map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
		std::cout << rit->first << " => " << rit->second << '\n';
}

void	map_empty()
{
	map<char,int> mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
}

void	map_size()
{
	map<char,int> mymap;
	mymap['a']=101;
	mymap['b']=202;
	mymap['c']=302;

	std::cout << "mymap.size() is " << mymap.size() << '\n';
}

void	map_max_size()
{
	int i;
	map<int,int> mymap;

	if (mymap.max_size()>1000)
	{
		for (i=0; i<1000; i++) mymap[i]=0;
		std::cout << "The map contains 1000 elements.\n";
	}
	else std::cout << "The map could not hold 1000 elements.\n";
}

void	map_operator(void)
{
	map<char,std::string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}

void	map_insert()
{
	map<char,int> mymap;

	mymap.insert ( pair<char,int>('a',100) );
	mymap.insert ( pair<char,int>('z',200) );

	pair<map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( pair<char,int>('z',500) );
	if (ret.second==false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, pair<char,int>('b',300));
	mymap.insert (it, pair<char,int>('c',400));

	map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	std::cout << "mymap contains:\n";
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	map_erase()
{
	map<char,int> mymap;
	map<char,int>::iterator it;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

	it = mymap.find('b');
	mymap.erase (it);

	mymap.erase ('c');

	it = mymap.find ('e');
	mymap.erase ( it, mymap.end() );

	// show content:
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	map_swap()
{
	map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (map<char,int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	map_clear()
{
	map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (map<char,int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	map_find()
{
	map<char,int> mymap;
	map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase (it);

	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}

void	map_count()
{
	map<char,int> mymap;
	char c;

	mymap ['a']=101;
	mymap ['c']=202;
	mymap ['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else 
			std::cout << " is not an element of mymap.\n";
	}
}

void	map_lower_upper()
{
	map<char,int> mymap;
	map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow = mymap.lower_bound ('b');  // itlow points to b
	itup = mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

void	map_equal()
{
	map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	pair<map<char,int>::iterator, map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

void	map_allocator()
{
	int psize;
	map<char,int> mymap;
	pair<const char,int>* p;

	p=mymap.get_allocator().allocate(5);

	psize = sizeof(std::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);
}

void	map_tests(void)
{
	std::cout << "\n------------------------------ TESTING MAP CONTAINER -------------------------------------------------" << std::endl;
	std::cout << "\nMap test begin() and end() \n" << std::endl;
	map_begin_end();
	std::cout << "\nMap test rbegin() and rend() \n" << std::endl;
	map_rbegin_rend();
	std::cout << "\nMap test empty()\n" << std::endl;
	map_empty();
	std::cout << "\nMap test size()\n" << std::endl;
	map_size();
	std::cout << "\nMap test max_size()\n" << std::endl;
	map_max_size();
	std::cout << "\nMap test operator[]()\n" << std::endl;
	map_operator();
	std::cout << "\nMap test insert()\n" << std::endl;
	map_insert();
	std::cout << "\nMap test erase()\n" << std::endl;
	map_erase();
	std::cout << "\nMap test swap()\n" << std::endl;
	map_swap();
	std::cout << "\nMap test clear()\n" << std::endl;
	map_clear();
	std::cout << "\nMap test find()\n" << std::endl;
	map_find();
	std::cout << "\nMap test count()\n" << std::endl;
	map_count();
	std::cout << "\nMap test lower_bound() and upper_bound()\n" << std::endl;
	map_lower_upper();
	std::cout << "\nMap test equal_range()\n" << std::endl;
	map_equal();
	std::cout << "\nMap test get_allocator()\n" << std::endl;
	map_allocator();
}