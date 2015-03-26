// 
// ex13_18.cpp
// Exercise 13.18
// 
// Created by DestinyOMGwz on 3/26/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Define an Employee class that contains an employee name
// and a unique employee identifier. Give the class a default constructor
// and a constructor that takes a string representing the employee's name. 
// Each constructor should generate a unique ID by incrementing a static data
// member

#include <string>

class Employee
{
public:
	static int num;
	Employee() : eID(num++) {}

	Employee(const std::string& s) : eID(num++), eName(s) {}

	Employee(const Employee&) = delete;

	Employee& operator=(const Employee& source) = delete;

	~Employee() {}

private:
	int eID;
	std::string eName;
};