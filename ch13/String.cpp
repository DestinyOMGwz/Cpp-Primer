#include "String.h"
#include <algorithm>
#include <iostream>

std::allocator<char> String::alloc;

// private functionality
std::pair<char*, char*> 
String::alloc_n_copy(const char *b, const char *e)
{
	auto newdata = alloc.allocate(e - b);
	return { newdata, std::uninitialized_copy(b, e, newdata) };
}

void String::free()
{
	if (elements){
		std::for_each(elements, first_free, [](char &c){ alloc.destroy(&c); });
		alloc.deallocate(elements, first_free - elements);
	}
}

// Constructor
String::String() : elements(nullptr), first_free(nullptr) {}

String::String(const char *c)
{
	char *c1 = const_cast<char*>(c);
	while (*c1){
		++c1;
	}
	auto newdata = alloc_n_copy(c, c1);
	elements = newdata.first;
	first_free = newdata.second;	
}

String::String(const String &source)
{
	std::cout << "Copy constructor is called" << std::endl;
	auto newdata = alloc_n_copy(source.elements, source.first_free);
	elements = newdata.first;
	first_free = newdata.second;
}

String::String(String &&source) : elements(source.elements), first_free(source.first_free)
{
	std::cout << "move constructor is called" << std::endl;
	elements = first_free = nullptr;
}

String& String::operator=(String &&rhs)
{
	std::cout << "move assignment operator is called" << std::endl;
	if (this != &rhs){
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		rhs.elements = rhs.first_free = nullptr;
	}
	return *this;	
}

String::~String()
{
	free();
}

String& String::operator=(const String &rhs)
{
	std::cout << "Copy assignment operator" << std::endl;
	auto newdata = alloc_n_copy(rhs.elements, rhs.first_free); 
	free();
	elements = newdata.first;
	first_free = newdata.second;
	return *this;
}

size_t String::size() const
{
	return first_free - elements;
}
