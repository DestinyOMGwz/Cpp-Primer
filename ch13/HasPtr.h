#ifndef _HASPTR_H_
#define _HASPTR_H_

#include <string>
#include <iostream>

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
	HasPtr& operator=(HasPtr source)
	{
		swap(*this, source);		
		return *this;
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