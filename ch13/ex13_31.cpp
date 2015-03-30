// 
// ex13_31.cpp
// Exercise 13.31
// 
// Created by DestinyOMGwz on 3/26/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Give your class a < operator and define a vector of HasPtrs.
// Give that vector some elements and then sort the vector.
// Note the swap is called.

#include "HasPtr.h"
#include <vector>
#include <algorithm>

int main()
{
	std::vector<HasPtr> v;
	v.push_back(HasPtr("zebra"));
	v.push_back(HasPtr("apple"));
	v.push_back(HasPtr("milk"));
	v.push_back(HasPtr("banana"));
	std::sort(v.begin(), v.end());
	return 0;
}