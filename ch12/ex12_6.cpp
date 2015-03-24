#include <vector>
#include <iostream>

std::vector<int>* dynamicVector(const std::initializer_list<int> &il);
void print(const std::vector<int> *p);

int main()
{
	std::vector<int> *p = dynamicVector(std::initializer_list<int>{ 1, 2, 3, 4, 5, 6, 7 });
	print(p);
	delete p;
	return 0;
}

std::vector<int>* dynamicVector(const std::initializer_list<int> &il)
{
	return new std::vector<int>(il);
}

void print(const std::vector<int> *p)
{
	for (int i : *p)
		std::cout << i << std::endl;
}