// 
// ex12_10_11.cpp
// Exercise 12.10 and 12.11
// 
// Created by DestinyOMGwz on 3/24/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Explain whether the following call to the process function defined on page
// 464 is correct. If not, how would you correct the call?
//
// What happened if we called process as follows?

#include <memory>
#include <iostream>

void process(std::shared_ptr<int> p);

int main()
{
	std::shared_ptr<int> p(new int(42));
	std::cout << p.use_count() << std::endl;
	process(std::shared_ptr<int>(p));
	std::cout << p.use_count() << std::endl;

	std::cout << "Another exercise" << std::endl;
	// it is error to use get to initialize another smart pointer
	// process(std::shared_ptr<int>(p.get()));
	// std::cout << p.use_count() << std::endl;

	return 0;
}


void process(std::shared_ptr<int> p)
{
	std::cout << "In the function process: " << p.use_count() << std::endl;
}