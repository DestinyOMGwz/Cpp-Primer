#include "StrBlob.h"
#include "StrBlobPtr.h"

// Constructor
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(const std::initializer_list<std::string> &il) : data(std::make_shared<std::vector<std::string>>(il)) {}

StrBlob::~StrBlob() {}

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const
{
	if (i >= data->size()) throw std::out_of_range(msg);
}

// Accessing function
StrBlob::size_type StrBlob::size() const
{
	return data->size();
}

bool StrBlob::empty() const
{
	return data->empty();
}

std::string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

StrBlobPtr StrBlob::begin() const
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() const
{
	return StrBlobPtr(*this, data->size());
}

// Functionality

void StrBlob::push_back(const std::string &t)
{
	data->push_back(t);
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

