// 
// ex11_33.cpp
// Exercise 11.33
// 
// Created by DestinyOMGwz on 3/22/15
// Modified on pezy's program
//
// Implement your own version of the word-transformation program

#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

void word_transform(std::ifstream&, std::ifstream&);

int main()
{
	std::ifstream map_file("transformRule.txt"), input("inputText.txt");
	if (map_file && input)
		word_transform(map_file, input);
	return 0;
}

void word_transform(std::ifstream &map_file, std::ifstream &input)
{
	std::map<std::string, std::string> trans_map;
	// using for to simplify the code, although it is less readable than the previous one
	for (std::string key, value; map_file >> key && std::getline(map_file, value);)
		trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(' '));
	for (std::string text, word; std::getline(input, text); std::cout << std::endl)
		for (std::istringstream is(text); is >> word; std::cout << " "){
			auto map_it = trans_map.find(word);
			std::cout << (map_it == trans_map.end() ? word : map_it->second);
		}
}