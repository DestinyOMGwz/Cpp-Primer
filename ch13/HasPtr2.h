#ifndef _HASPTR2_H_
#define _HASPTR2_H_

#include <string>

class HasPtr2
{
public:
	HasPtr2(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new int(1)) {};

	HasPtr2(const HasPtr2& source) : ps(source.ps), i(source.i), use(source.use)
	{
		++*source.use;
	}
	HasPtr2& operator=(const HasPtr2& source)
	{
		++*source.use;
		std::string *newps = source.ps;
		if (--*use == 0){
			delete ps;
			delete use;
		}
		ps = newps;
		use = source.use;
		i = source.i;
		return *this;
	}

	~HasPtr2() 
	{
		if (--*use == 0){
			delete ps;
			delete use;
		}
	}

private:
	std::string *ps;
	int i;
	int *use;
};

#endif