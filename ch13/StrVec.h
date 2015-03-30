#ifndef _STRVEC_H_
#define _STRVEC_H_
#include <memory>
#include <string>
#include <utility>
#include <iostream>

class StrVec
{
public:
	// Constructor
	StrVec();
	StrVec(const std::initializer_list<std::string> &il);
	StrVec(const StrVec&);
	StrVec(StrVec&&);
	StrVec &operator=(const StrVec&);
	StrVec &operator=(StrVec&&);
	~StrVec();

	// Accessing function
	void push_back(const std::string&);
	size_t size() const;
	size_t capacity() const;
	std::string *begin() const;
	std::string *end() const;

	// Functionality
	void reserve(size_t newcap);
	void resize(size_t newsize, const std::string &s);
	void resize(size_t newsize);
	
	

private:
	static std::allocator<std::string> alloc;
	std::string *elements;
	std::string *first_free;
	std::string *cap;

	// private functionality
	void check_n_alloc();
	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void reallocate();
	

	void alloc_n_move(size_t newcap);
};


#endif