#ifndef _TEXTQUERY_H_
#define _TEXTQUERY_H_
#include <map>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <memory>

class QueryResult;

class TextQuery
{
public:
	typedef std::map<std::string, std::shared_ptr<std::set<int>>> SSMap;
	typedef std::map<std::string, int> SIMap;
	// Constructors
	TextQuery();
	TextQuery(std::ifstream&);
	~TextQuery();

	// Function
	void inputQuery(std::ifstream&);
	QueryResult result() const;
	
	QueryResult query(const std::string&) const;

private:
	std::shared_ptr<std::vector<std::string>> lines;
	SSMap occurs;
	SIMap freqs;
	void doQueries(std::ifstream&);
};

#endif