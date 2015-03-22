// 
// ex11_12.cpp
// Exercise 11.14
// 
// Created by DestinyOMGwz on 3/21/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Extend the map of children to their family name that wrote for the exercises in 11.21
// by having the vector store a pair that holds a child's name and birthday.

#include <iostream>
#include <vector>
#include <string>
#include <map>

typedef std::vector<std::pair<std::string, std::string> > SPairVector;

int main()
{
	// declare the variables
	std::map<std::string, SPairVector> family;
	std::string last, cname, birthday;
	while ([&]{
		// using lambda to output the hint
		std::cout << "Please input the last name of the family: ";
		// I'm not sure why it is not correct if I don't add &&1 here
		return std::cin >> last && 1;
		
	}()){
		// Intialize the vector
		SPairVector children;
		while ([&]{
			// use lambda to output the hint
			std::cout << "Please input the child name: ";
			std::cin >> cname;
			std::cout << "Please input the birthday: ";
			std::cin >> birthday;
			if (std::cin.fail()){
				// if the input is fail, break the inner loop and reset cin, else do the loop
				std::cin.clear();
				std::cout << std::endl;
				return 0;
			}
			return 1;
		}()){
			children.push_back(std::make_pair(cname, birthday));
		}
		family[last] = children;
	}

	//output the result
	for (auto p : family){
		std::cout << p.first << " family:" << std::endl;
		for (auto p2 : p.second)
			std::cout << p2.first << " " << p2.second << " ";
		std::cout << std::endl;
	}
	return 0;
}
