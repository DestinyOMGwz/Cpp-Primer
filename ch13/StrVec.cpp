#include "StrVec.h"
#include <algorithm>

std::allocator<std::string> StrVec::alloc;

// private functionality
void StrVec::check_n_alloc()
{
	if (size() == capacity())
		reallocate();
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
	if (elements){
		// using for loop
		/*for (auto p = first_free; p != elements;)
			alloc.destroy(p--);*/
		// using for each
		std::for_each(elements, first_free, [](std::string &s){
			alloc.destroy(&s);
		});
		alloc.deallocate(elements, cap - elements);
	}
}


void StrVec::reallocate()
{
	auto newcapacity = size() ? size() * 2 : 1;
	alloc_n_move(newcapacity);
}

void StrVec::alloc_n_move(size_t newcap)
{
	auto newdata = alloc.allocate(newcap);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcap;
}

// Constructors
StrVec::StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

StrVec::StrVec(const StrVec &source)
{
	auto newdata = alloc_n_copy(source.begin(), source.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const std::initializer_list<std::string> &il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&source) : elements(source.elements), first_free(source.first_free), cap(source.cap)
{
	source.elements = source.first_free = source.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs)
{
	if (this != &rhs){
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::~StrVec()
{
	free();
}

// Functionality
void StrVec::push_back(const std::string &str)
{
	check_n_alloc();
	alloc.construct(first_free++, str);	
}

size_t StrVec::size() const
{
	return first_free - elements;
}

size_t StrVec::capacity() const
{
	return cap - elements;
}

std::string *StrVec::begin() const
{
	return elements;
}

std::string *StrVec::end() const
{
	return first_free;
}

// Functionality
void StrVec::reserve(size_t newcap)
{
	if (newcap > capacity())
		alloc_n_move(newcap);
}

void StrVec::resize(size_t newsize, const std::string &s)
{
	if (newsize > capacity())
		reserve(newsize * 2);
	if (newsize > size()){
		for (int i = size(); i != newsize; ++i)
			alloc.construct(first_free++, s);
	}else{
		for (int i = size(); i != newsize; --i)
			alloc.destroy(--first_free);
	}
}

void StrVec::resize(size_t newsize)
{
	resize(newsize, std::string());
}