# FT_CONTAINERS

## About
The goal of this project is to reproduce some c++ stl containers. All the program is in c++ 98, and all the containers are in a namespace called *ft*. All member functions, Non-member and overloads are expected.
The iterators system and binary search tree, necessary for the map, were implement. Others classes, such as enable_if, is_integral, equal/lexicographical compare, std::pair, std::make_pair, were reimplemented too.

## Containers

### Vector
* Has all member and non-member functions, also has differents types of iterators

### Stack
* Using vector class as default underlaying container, but can be changed to others STL containers, such as deque and list.

### Map
* Implemented using a Binary Search Tree algorithm

## How to use
1. Clone repository
```
git@github.com:marco-kraemer/ft_containers.git
```
2. Compile and run tests
```
make run
```
* 2 outfiles will be generate. One testing ft_containers and one with the originals containers. They can be compared using *diff* command.
