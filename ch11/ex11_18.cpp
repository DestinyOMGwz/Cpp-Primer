// 
// ex11_18.cpp
// Exercise 11.18
// 
// Created by DestinyOMGwz on 3/21/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Write the type of map_it from the loop on page 430
// without using auto or decltype

#include <map>
#include <iostream>
#include <string>


int main()
{
	std::map<std::string, int> word_count;
	std::map<std::string, int>::const_iterator map_it = word_count.cbegin();
	while (map_it != word_count.cend()){
		std::cout << map_it->first << " occurs "
			<< map_it->second << " times" << std::endl;
		++map_it;
	}
	return 0;
}