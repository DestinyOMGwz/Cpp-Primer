// 
// ex11_31.cpp
// Exercise 11.31
// 
// Created by DestinyOMGwz on 3/21/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Write a program that defines a multimap of authors and their works.
// Use find to find an element in the multimap and erase that element.
// Be sure your program works correctly if the element you look for is not in the map.

#include <map>
#include <iostream>
#include <string>

int main()
{
	std::multimap<std::string, std::string> library{ { "Destiny", "I believe in you" }, { "Destiny", "Coding is your faith" }, {"Destiny", "Don't be shy"} };
	for (auto rag = library.equal_range("Destiny"); rag.first != library.end() && rag.first != rag.second;){
		if ((rag.first->second) == "Coding is your faith") rag.first = library.erase(rag.first);
		else ++rag.first;
	}
	for (auto p : library)
		std::cout << p.first << " writes " << p.second << std::endl;
	return 0;
}