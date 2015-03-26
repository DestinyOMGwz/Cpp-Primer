#ifndef _QUERYRESULT_H_
#define _QUERYRESULT_H_
#include "TextQuery.h"

class QueryResult
{
public:
	QueryResult(const std::string&, const std::vector<std::string>&, const std::set<int>&, int n);
	~QueryResult();

	// Functionality
	friend std::ostream& print(std::ostream&, const QueryResult&);

private:
	std::string word;
	std::shared_ptr<std::vector<std::string>> line;
	std::shared_ptr<std::set<int>> occur;
	int freq;
};

std::ostream& print(std::ostream&, const QueryResult&);

#endif