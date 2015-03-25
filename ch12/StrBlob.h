// 
// StrBlob.h
// Exercise 12.1
// 
// Created by DestinyOMGwz on 3/23/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Write your own version of the StrBlob class including the const versions of front and back.

#ifndef _STRBLOB_H_
#define _STRBLOB_H_
#include <memory>
#include <string>
#include <vector>

// class StrBlobPtr;

class StrBlob
{
public:
	typedef std::vector<std::string>::size_type size_type;
	friend class StrBlobPtr;
	// Constructors
	StrBlob();
	StrBlob(const std::initializer_list<std::string> &il);
	virtual ~StrBlob();

	// Accessing functions
	size_type size() const;
	bool empty() const;
	std::string& front();
	std::string& back();
	const std::string& front() const;
	const std::string& back() const;
	StrBlobPtr begin() const;
	StrBlobPtr end() const;
	

	// Functionality
	void push_back(const std::string &t);
	void pop_back();

	

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};

#endif