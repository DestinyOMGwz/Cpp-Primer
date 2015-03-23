// 
// ex11_33.cpp
// Exercise 11.33
// 
// Created by DestinyOMGwz on 3/22/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Implement your own version of the word-transformation program

#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

void word_transform(std::ifstream&, std::ifstream&);
std::map<std::string, std::string> buildMap(std::ifstream&);
std::string transform(const std::string&, const std::map<std::string, std::string>&);

int main()
{
	std::ifstream map_file("transformRule.txt");
	std::ifstream input("inputText.txt");
	if (map_file && input)
		word_transform(map_file, input);
	return 0;
}

void word_transform(std::ifstream &map_file, std::ifstream &input)
{
	// read file and build the map for transform
	std::map<std::string, std::string> trans_map = buildMap(map_file);
	std::string text;
	// transform the word in input file
	while (getline(input, text)){
		std::istringstream is(text);
		std::string word;
		// if it is not the first word, ouput " " to seperate
		bool firstword = true;
		while (is >> word){
			if (firstword)
				firstword = false;
			else
				std::cout << " ";
			// do the transform
			std::cout << transform(word, trans_map);
		}
		std::cout << std::endl;
	}
}

std::map<std::string, std::string> buildMap(std::ifstream &map_file)
{
	// read the information for transform to build a map, if no value for the key
	// throw out runtime error
	std::map<std::string, std::string> trans_map;
	std::string key;
	while (map_file >> key){
		std::string value;
		if (getline(map_file, value))
			trans_map[key] = value.substr(1);
		else
			throw std::runtime_error("No transform for " + key);
	}
	return trans_map;
}

std::string transform(const std::string &word, const std::map<std::string, std::string> &trans_map)
{
	// do the transform according to the map
	auto map_it = trans_map.find(word);
	if (map_it == trans_map.end())
		return word;
	return map_it->second;
}