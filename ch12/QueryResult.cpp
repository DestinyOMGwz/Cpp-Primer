#include "QueryResult.h"
#include "TextQuery.h"
#include <iostream>

QueryResult::QueryResult(const std::string &s, const std::vector<std::string> &v, const std::set<int> &num, int n) : word(s),
line(std::make_shared<std::vector<std::string>>(v)),
occur(std::make_shared<std::set<int>>(num)), freq(n) {}

QueryResult::~QueryResult() {}

std::ostream& print(std::ostream &os, const QueryResult &qr)
{
	if (qr.freq == 0)
		std::cout << qr.word << " Cannot be found in the file" << std::endl;
	else{
		std::cout << qr.word << " ocurrs " << qr.freq << " times" << std::endl;
		for (auto i : *(qr.occur))
			std::cout << "   " << " (line " << i + 1 << " ) " 
				<< (qr.line)->at(i) << std::endl;
	}
	return os;
}