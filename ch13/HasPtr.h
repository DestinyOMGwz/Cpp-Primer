#ifndef _HASPTR_H_
#define _HASPTR_H_

#include <string>
#include <iostream>

class HasPtr
{
public:
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {};
	
	
	HasPtr(const HasPtr& source) : ps(new std::string(*source.ps)), i(source.i) {}
	HasPtr(HasPtr &&source) :ps(source.ps), i(source.i)
	{
		source.ps = 0;
	}
	HasPtr& operator=(HasPtr source)
	{
		swap(*this, source);		
		return *this;
	}
	/*HasPtr& operator=(const HasPtr &rhs)
	{
		auto p = new std::string(*rhs.ps);
		delete ps;
		ps = p;
		i = rhs.i;
		return *this;
	}

	HasPtr& operator=(HasPtr &&rhs)
	{
		if (this != &rhs){
			delete ps;
			ps = rhs.ps;
			i = rhs.i;
			rhs.ps = 0;
		}
		return *this;
	}*/

	bool operator<(const HasPtr &rhs)
	{
		return *ps < *rhs.ps;
	}

	~HasPtr() { delete ps; };

	friend void swap(HasPtr &lfs, HasPtr &rhs);

private:
	std::string *ps;
	int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	std::cout << "swap HasPtr!" << std::endl;
}

#endif