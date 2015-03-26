// 
// ex13_27.cpp
// Exercise 13.27
// 
// Created by DestinyOMGwz on 3/26/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Define your own reference-counted version of HasPtr

#include <string>


class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {};

	// Copy behave like pointer, in this case is a bad design
	/*HasPtr(const HasPtr& source) : ps(source.ps), i(source.i) {}
	HasPtr& operator=(const HasPtr& source)
	{
		if (ps == source.ps)
			return *this;
		if (!ps) delete ps;
		i = source.i;
		ps = source.ps;
		return *this;
	}*/

	// copy behave like value
	HasPtr(const HasPtr& source) : ps(new std::string(*source.ps)), i(source.i) {}
	HasPtr& operator=(const HasPtr& source)
	{
		if (ps == source.ps)
			return *this;
		if (!ps) delete ps;
		i = source.i;
		ps = new std::string(*source.ps);
		return *this;
	}
	~HasPtr() { delete ps; };

private:
	std::string *ps;
	int i;
};

int main()
{

	return 0;
}