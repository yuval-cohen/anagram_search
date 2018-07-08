#include <iostream>
#include <fstream>

#include "word_list.h"


bool WordList::ReadWordList(const char* file_name)
{
	ifstream file;
	file.open(file_name);
	if (file.is_open() == false)
		return false;

	string word;
	int count = 0;
	getline(file, word);
	while (file) // while input is good
	{
		list.insert(word);
		no_of_words++;
		getline(file, word);
	}
	file.close();

	return true;
}

bool WordList::FindWord(const string &word) const
{
	if (list.find(string(word)) != list.end())
		return true;

	return false;
}
