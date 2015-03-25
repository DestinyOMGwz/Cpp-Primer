// 
// StrBlobPtr.h
// Exercise 12.19
// 
// Created by DestinyOMGwz on 3/25/15
// Copyright (c) 2015 DestinyOMGwz. All rights reserved.
//
// Define your own version of StrBlobPtr and update your StrBlob class

#ifndef _STRBLOBPTR_H_
#define _STRBLOBPTR_H_
#include <memory>
#include <vector>
#include <string>
#include "StrBlob.h"

class StrBlobPtr
{
public:
	// Constructors
	StrBlobPtr();
	StrBlobPtr(const StrBlob &a, size_t sz = 0);
	virtual ~StrBlobPtr();

	// Accessing function
	std::string& deref() const;

	// Functionality
	StrBlobPtr& incr();

private:
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;

	// private function
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

};

#endif