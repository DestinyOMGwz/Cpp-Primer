// 
// ex11_20.cpp
// Exercise 11.20
// 
// Created by DestinyOMGwz on 3/21/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Rewrite the word_counting program from 11.1 to use insert instead of subscripting. 
// Which program do you think is easier to write and read? Explain your reasoning.
// 
// I think subscripting is better for reading and writing since It is very simple to write and
// can be understand very easily.

#include <map>
#include <iostream>
#include <string>

int main()
{
	std::map<std::string, size_t> word_count;
	std::string word;
	while (std::cin >> word){
		auto ret = word_count.insert({ word, 1 });
		if (!ret.second) ++ret.first->second;
	}

	for (const auto &w : word_count)
		std::cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times!" : " time!") << std::endl;
	return 0;
	
}