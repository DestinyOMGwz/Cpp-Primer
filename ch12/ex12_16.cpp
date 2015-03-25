// 
// ex12_16.cpp
// Exercise 12.16
// 
// Created by DestinyOMGwz on 3/24/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Compilers don't always give easy-to-understand error messages 
// if we attempt to copy or assign a unique_ptr. Write a program that contains
// these errors to see how your compilers diagnoses them.
#include <memory>

int main()
{
	// std::unique_ptr<int> p1 = new int(); Cannot use assignment operator to initialize the unique_ptr
	std::unique_ptr<int> p1(new int());
	// std::unique_ptr<int> p2(p1); Cannot use copy constructor to initialize the unique_ptr
	return 0;
}