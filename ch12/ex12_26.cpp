// 
// ex12_26.cpp
// Exercise 12.26
// 
// Created by DestinyOMGwz on 3/25/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Rewrite the program on page 481 using an allocator

#include <memory>
#include <string>
#include <iostream>

int main()
{
	int n = 10;
	std::allocator<std::string> a;
	std::string s;
	auto const p = a.allocate(n);
	auto *q = p;
	while (std::cin >> s && q != p + n)
		a.construct(q++, s);
	while (q != p)
		a.destroy(--q);
	a.deallocate(p, n);
	return 0;
}