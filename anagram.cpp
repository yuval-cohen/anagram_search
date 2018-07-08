#include <algorithm>
#include <iterator>
#include <cctype>

#include "anagram.h"


void Anagram::ResetPhrase(const string &_phrase)
{
	phrase = _phrase;
	root_anagram = "";
	multi_anagram_index = 0;
}


Anagram::NextAnagramRc Anagram::NextAnagram(vector<string> &angrm)
{
	using std::copy;
	using std::back_insert_iterator;

	if (phrase == "")
		return NextAnagramRc::No_Phrase;

	if (phrase.size() > MAX_ANAGRAM_LEN)
		return NextAnagramRc::Phrase_Too_Long;

	if (root_anagram == "")
	{
		/* removes space and punctuations and transform to lowercase */
		std::remove_copy_if(phrase.cbegin(), phrase.cend(), std::back_inserter(root_anagram), [](int x) { return isspace(x) || ispunct(x); });
		std::transform(root_anagram.begin(), root_anagram.end(), root_anagram.begin(), tolower);

		/* create initial root anagram */
		sort(root_anagram.begin(), root_anagram.end());
		multi_anagram_index = 0;
	}
	else if (multi_anagram_index == long(pow(2, root_anagram.size() - 1)))
	{
		if (next_permutation(root_anagram.begin(), root_anagram.end()))
		{
			multi_anagram_index = 0;
		}
		else
			return NextAnagramRc::End_Of_Output;
	}

	next_multi_anagram();

	angrm = vector<string>();
	copy(multi_anagram.begin(), multi_anagram.end(), back_insert_iterator<vector<string>>(angrm));

	return NextAnagramRc::Next_Found;
}


void Anagram::next_multi_anagram()
{
	// input: root_anagram, multi_anagram_index
	// output: multi_anagram with all words
	multi_anagram = vector<string>();

	if (multi_anagram_index == 0)
	{
		multi_anagram.push_back(root_anagram);
	}
	else
	{
		long multi_anagram_index_bit;
		int start, end;
		for (multi_anagram_index_bit = 1, start = 0, end = 0; multi_anagram_index_bit < long(pow(2, root_anagram.size())); multi_anagram_index_bit <<= 1, end++)
		{
			if (multi_anagram_index & multi_anagram_index_bit)
			{
				multi_anagram.push_back(root_anagram.substr(start, end-start+1));
				start = end + 1;
			}
		}
		multi_anagram.push_back(root_anagram.substr(start, end - start));
	}
	multi_anagram_index++;
}
