// 
// ex12_6.cpp
// Exercise 12.6
// 
// Created by DestinyOMGwz on 3/23/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Write a function that returns a dynamically allocated vector of ints.
// Pass that vector to another function that reads the standard input to give values to
// the elements. Pass the vector to another function to print the values that were read
// Remember to delete the vector at the appropriate time.

#include <vector>
#include <iostream>

std::vector<int>* dynamicVector(const std::initializer_list<int> &il);
void print(const std::vector<int> *p);

int main()
{
	std::vector<int> *p = dynamicVector(std::initializer_list<int>{ 1, 2, 3, 4, 5, 6, 7 });
	print(p);
	delete p;
	return 0;
}

std::vector<int>* dynamicVector(const std::initializer_list<int> &il)
{
	return new std::vector<int>(il);
}

void print(const std::vector<int> *p)
{
	for (int i : *p)
		std::cout << i << std::endl;
}