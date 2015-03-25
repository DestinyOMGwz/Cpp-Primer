#include "StrBlobPtr.h"

// private function
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
	auto p = wptr.lock();
	if (!p)
		throw std::runtime_error("unbounded StrBlobPtr!");
	if (i >= p->size())
		throw std::out_of_range(msg);
	return p;
}

// Constructors
StrBlobPtr::StrBlobPtr() : curr(0) {}

StrBlobPtr::StrBlobPtr(const StrBlob &b, std::size_t sz) : wptr(b.data), curr(sz) {}

StrBlobPtr::~StrBlobPtr() {}

// Accessing function
std::string& StrBlobPtr::deref() const
{
	auto p = check(curr, "deref past end");
	return (*p)[curr];
}

// Functionality
StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "incr past end");
	++curr;
	return *this;
}