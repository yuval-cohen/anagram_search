#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Anagram
{
private:
	string phrase = "";
	string root_anagram = "";
	vector<string> multi_anagram;
	long multi_anagram_index = 0;

	void next_multi_anagram();
public:

	enum class NextAnagramRc { No_Phrase, Phrase_Too_Long, Next_Found, End_Of_Output };
	static const long MAX_ANAGRAM_LEN = 30;

	Anagram() = default;
	Anagram(const string &_phrase) : phrase(_phrase) {}
	~Anagram() = default;
	void ResetPhrase(const string &_phrase);
	NextAnagramRc NextAnagram(vector<string> &angrm);
};