// 
// ex11_12.cpp
// Exercise 11.12 11.13
// 
// Created by DestinyOMGwz on 3/21/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Write a program to read a sequence of strings and ints, 
// storing each into a pair. Store the pairs in a vector.
//
// There are at least three ways to create the pairs in the program for
// the previous exercise. Write three versions of that program,
// creating the pairs in each way. Explain which form you think is easiest to
// write and understand, and why.

#include <string>
#include <iostream>
#include <vector>

typedef std::pair<std::string, int> SIntPair;

SIntPair readPairs(std::istream& = std::cin);

int main()
{
	std::vector<SIntPair> vec;
	std::string jud;
	while ([&]{
		std::cout << "Do you want to type in a Pair (Y or N): ";
		return (std::cin >> jud) && (jud == "Y");
	}()){
		vec.push_back(readPairs());	
	}
	for (SIntPair si : vec)
		std::cout << si.first << ": " << si.second << std::endl;
	return 0;
}

SIntPair readPairs(std::istream& is)
{
	std::string str;
	int num;
	is >> str >> num;
	// return { str, num };
	// return SIntPair(str, num);
	return std::make_pair(str, num);
}