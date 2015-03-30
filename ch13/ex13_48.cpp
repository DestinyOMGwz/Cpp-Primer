// 
// ex13_48.cpp
// Exercise 13.48
// 
// Created by DestinyOMGwz on 3/29/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Define a vector<String> and call push_back several times on
// that vector. Run your program and see how often Strings are copied

#include "String.h"
#include <vector>
#include <string>

String result(String word);

int main()
{
	std::vector<String> vec;
	vec.push_back("abc");
	vec.push_back(String("bac"));
	vec.push_back(String("a12"));
	// String a = result("abc");
	vec.push_back(result("abc"));
	return 0;
}

String result(String word)
{
	return word;
}