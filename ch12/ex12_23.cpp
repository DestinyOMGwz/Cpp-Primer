// 
// ex12_23.cpp
// Exercise 12.23, 12.24
// 
// Created by DestinyOMGwz on 3/25/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Write a program to concatenate two string literals, putting the result in
// a dynamically allocated array of char. Write a program to concatenate two library
// strings that have the same value as the literals used in the first program.
//
// Write a program that reads a string from the standard input into a dynamically
// allocated character array. Describe how your program handles varying size inputs
// Test your program by giving it a string of data that is longer than the array size
// you've allocated.

#include <memory>
#include <string>
#include <iostream>

char* concatenateStrings(const std::string&, const std::string&);

int main()
{
	std::string s1, s2;
	std::cin >> s1 >> s2;
	char *p = concatenateStrings(s1, s2);
	for (int i = 0; i != s1.size() + s2.size() ; i++)
		std::cout << p[i];
	delete [] p;
	return 0;
}

char* concatenateStrings(const std::string &s1, const std::string &s2)
{
	std::string s = s1 + s2;
	int n = s.size();
	char *p = new char[n];
	// char *p = new char[n-2]; Error: write the memory after the heap buffer
	for (int i = 0; i != n; ++i)
		p[i] = s[i];
	return p;
}