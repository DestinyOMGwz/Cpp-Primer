#include "TextQuery.h"
#include <sstream>
#include <algorithm>
#include "QueryResult.h"
#include <iostream>

// private functionality
void TextQuery::doQueries(std::ifstream &in)
{
	if (!in.is_open())
		throw std::runtime_error("File cannot find");
	for (std::string text, word; std::getline(in, text);){
		lines->push_back(text);
		for (std::istringstream is(text); is >> word; ++freqs[word]){
			*word.begin() = tolower(*word.begin());
			auto &p = occurs[word];
			if (!p) p = std::make_shared<std::set<int>>();
			occurs[word]->insert(lines->size());
		}
	}
}

// Constructors
TextQuery::TextQuery() : lines(std::make_shared<std::vector<std::string>>()) {}

TextQuery::TextQuery(std::ifstream &in) : lines(std::make_shared<std::vector<std::string>>())
{
	doQueries(in);
}

TextQuery::~TextQuery() {}

// Functionality
void TextQuery::inputQuery(std::ifstream &in)
{
	lines->clear();
	occurs.clear();
	freqs.clear();
	doQueries(in);
}

QueryResult TextQuery::query(const std::string &s) const
{
	if(freqs.find(s) != freqs.end())
		return QueryResult(s, *lines, *(occurs.at(s)), freqs.at(s));
	return QueryResult(s, *lines, std::set<int>(), 0);
}
