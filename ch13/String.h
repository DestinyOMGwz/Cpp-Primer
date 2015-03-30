#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <memory>

class String
{
public:
	// Constructors
	String();
	String(const char*);
	String(const String&);
	String(String&&);
	String& operator=(const String&);
	String& operator=(String&&);
	~String();

	// Accessing
	size_t size() const;

private:
	std::pair<char*, char*> alloc_n_copy(const char*, const char*);
	void free();


private:
	static std::allocator<char> alloc;
	char *elements;
	char *first_free;
};


#endif