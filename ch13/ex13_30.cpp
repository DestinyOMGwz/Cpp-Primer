// 
// ex13_30.cpp
// Exercise 13.30
// 
// Created by DestinyOMGwz on 3/26/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Write and test a swap function for your valuelike version of HasPtr.
// Give your swap a print statement that notes when it is executed

#include "HasPtr.h"

int main()
{
	HasPtr p1("HasPtr2"), p2("HasPtr 2");
	// should output the result two times
	swap(p1, p2);
	p1 = p2;
	return 0;
}