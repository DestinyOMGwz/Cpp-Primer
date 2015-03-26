// 
// ex13_17.cpp
// Exercise 13.17
// 
// Created by DestinyOMGwz on 3/26/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Write version of numbered and f corresponding to the previous three
// exercises and check whether your correctly predicted the output
#include <iostream>

class numbered
{
public:
	static int num;
	numbered()
	{
		mysn = num++;
	}

	numbered(const numbered &s)
	{
		mysn = num++;
	}
	~numbered() {}

	int mysn;
};

// void f(numbered s) { std::cout << s.mysn << std::endl; }

void f(const numbered &s) { std::cout << s.mysn << std::endl; }

int numbered::num = 1;

int main()
{	
	
	numbered a, b = a, c = b;
	f(a); f(b); f(c);
	return 0;
}

// output
// For 14: 1, 1 ,1
// For 15: 4, 5, 6
// For 16: 1, 2, 3