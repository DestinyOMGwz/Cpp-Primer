// 
// ex12_14.cpp
// Exercise 12.14, 12.15
// 
// Created by DestinyOMGwz on 3/23/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Write your own version of a function that uses a shared_ptr to manage a connection

#include <memory>

struct destination{};
struct connection{};

connection connect(destination*) { return connection(); }
void end_connection(connection *p);
void disconnect(connection) {}
void f(destination &d);

int main()
{
	destination d;
	f(d);
	return 0;
}

void f(destination &d)
{
	connection c = connect(&d);
	// std::shared_ptr<connection>(&c, end_connection);
	std::shared_ptr<connection>(&c, [](connection *p){ disconnect(*p); });
}

void end_connection(connection *p)
{
	disconnect(*p);
}

