// 
// ex12_27.cpp
// Exercise 12.27
// 
// Created by DestinyOMGwz on 3/25/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// The Text Query and QueryResult classes use only capabilites that we have
// already covered. Without looking ahead, write your own versions of these
// classes

#include "TextQuery.h"
#include <iostream>
#include <memory>
#include "QueryResult.h"

int main()
{
	std::string filename("query.txt");
	std::ifstream in(filename);
	TextQuery tq(in);
	while (true){
		std::string word;
		std::cout << "Please input the word to do query: ";
		if (!(std::cin >> word) || word == "q") break;
		print(std::cout, tq.query(word)) << std::endl;
	}
	return 0;
}