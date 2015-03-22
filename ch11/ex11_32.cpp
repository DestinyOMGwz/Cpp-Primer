// 
// ex11_32.cpp
// Exercise 11.32
// 
// Created by DestinyOMGwz on 3/22/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Using the multimap from the previous exercise, write 
// a program to print the list of authors and their works alphabetically

#include <map>
#include <string>
#include <set>
#include <iostream>

int main()
{
	std::multimap<std::string, std::string> library{ { "Lilly", "A girl's life" },
	{ "Destiny", "I believe in you" }, { "Destiny", "Coding is your faith" }, { "Destiny", "Don't be shy" } };
	std::map<std::string, std::multiset<std::string>> order_library;
	for (const auto &book : library)
		order_library[book.first].insert(book.second);
	for (const auto &book : order_library){
		std::cout << book.first << " : ";
		for (const auto &item : book.second)
			std::cout << item << " | ";
		std::cout << std::endl;
	}
	return 0;
}