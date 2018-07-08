#include <iostream>
#include <iterator>
#include <vector>
#include <string>

#include "word_list.h"
#include "anagram.h"

//#define _MY_DEBUG_

int main(int argc, char* argv[])
{
	using std::vector;
	using std::ostream_iterator;
	using std::cout;
	using std::cerr;
	using std::endl;

	WordList wordList;
	bool word_list_ok;

#ifndef _MY_DEBUG_
	if ((argc < 3) || (strlen(argv[2]) > Anagram::MAX_ANAGRAM_LEN))
	{
		cout << "Usage: anagram_search.exe <word-list-file> <multiword phrase up to " << Anagram::MAX_ANAGRAM_LEN << " chars>\n";
	}
	else
#endif
	{
		cout << "reading word-list file... ";
#ifndef _MY_DEBUG_
		word_list_ok = wordList.ReadWordList(argv[1]);
#else
		word_list_ok = wordList.ReadWordList("word_x.list");
#endif
		cout << "[DONE]\n";

		if (word_list_ok)
		{
#ifndef _MY_DEBUG_
			string phrase_str;
			for (int i = 2; i < argc; i++)
			{
				phrase_str.append(argv[i]);
				if (i < argc-1)
					phrase_str.append(" ");
			}
			Anagram phrase(phrase_str);
			cout << "phrase = " << phrase_str << endl;
			cout << "anagrams found:\n";
#else
			Anagram phrase("I'm okay");
#endif

			vector<string> next_anagram;
			while (phrase.NextAnagram(next_anagram) == Anagram::NextAnagramRc::Next_Found)
			{
				bool all_anagram_words_found = true;

				for (auto iter = next_anagram.cbegin(); iter != next_anagram.cend(); iter++)
				{
					if (!wordList.FindWord(*iter))
					{
						all_anagram_words_found = false;
						break;
					}
				}

				if (all_anagram_words_found)
				{
					copy(next_anagram.begin(), next_anagram.end(), ostream_iterator<string, char>(cout, " "));
					cout << endl;
				}
					
			}

		}
		else
		{
			cerr << "Can't open file: " 
#ifndef _MY_DEBUG_
				<< argv[1] 
#endif
				<< endl;
		}
	}

	return 0;
}
