// 
// ex12_20.cpp
// Exercise 12.20
// 
// Created by DestinyOMGwz on 3/25/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Write a program that reads an input file a line at 
// a time into a StrBlob and uses a StrBlobPtr to print 
// each element in that StrBlob

#include "StrBlobPtr.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
	std::string filename = "StrFile.txt";
	std::ifstream input(filename);
	for (std::string text, word; std::getline(input, text);){
		StrBlob b;
		for (std::istringstream is(text); is >> word; b.push_back(word));
		for (auto p = b.begin(); p != b.end(); p.incr())
			std::cout << p.deref() << " ";
		std::cout << std::endl;
	}
	return 0;
}