// 

#include <string>
#include <iostream>
#include <vector>

typedef std::pair<std::string, int> SIntPair;

SIntPair readPairs(std::istream& = std::cin);

int main()
{
	std::vector<SIntPair> vec;
	std::string jud;
	while ([&]{
		std::cout << "Do you want to type in a Pair (Y or N): ";
		return (std::cin >> jud) && (jud == "Y");
	}()){
		vec.push_back(readPairs());	
	}
	for (SIntPair si : vec)
		std::cout << si.first << ": " << si.second << std::endl;
	return 0;
}

SIntPair readPairs(std::istream& is)
{
	std::string str;
	int num;
	is >> str >> num;
	return { str, num };
}