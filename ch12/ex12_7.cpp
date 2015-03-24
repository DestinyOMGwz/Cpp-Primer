// 
// ex12_7.cpp
// Exercise 12.7
// 
// Created by DestinyOMGwz on 3/23/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Redo the previous exercise, this time using shared_ptr.

#include <memory>
#include <vector>
#include <iostream>

std::shared_ptr<std::vector<int>> dynamicVector(const std::initializer_list<int> &il);
void print(const std::shared_ptr<std::vector<int>> &p);

int main()
{
	std::shared_ptr<std::vector<int>> p = dynamicVector(std::initializer_list<int>{ 1, 2, 3, 4, 5, 6, 7 });
	print(p);
	return 0;
}

std::shared_ptr<std::vector<int>> dynamicVector(const std::initializer_list<int> &il)
{
	return std::make_shared<std::vector<int>>(il);
}

void print(const std::shared_ptr<std::vector<int>> &p)
{
	for (int i : *p)
		std::cout << i << std::endl;
}