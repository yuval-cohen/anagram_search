#pragma once

#include <string>
#include <unordered_set>

using std::ifstream;


using std::unordered_set;
using std::string;

class WordList
{
private:
	unordered_set<string> list = unordered_set<string>();
	size_t no_of_words = 0; /* for statistics */

public:
	WordList() = default;
	~WordList() = default;
	bool ReadWordList(const char *file_name);
	bool FindWord(const string &word) const;
	size_t NoOfWords() { return no_of_words; }
};
