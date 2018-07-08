Anagram Search:

A program in C++ that finds anagrams of a given phrase from a word list file (such as .\word.list).

Usage: anagram.exe <word-list-file> <multiword phrase up to 30 chars>
e.g.
anagram_search.exe word.list real fun

Anagram is produced by rearranging the letters of a word or a phrase to produce another word or phrase, e.g.:
"funeral" and "real fun"
"forty five" and "over fifty"


Comments:
(1) The programs does output the input phrase (in case it is found)
(2) The programs expects word-list input file with one word in each line
(3) Emphasis is on the correctness of the program
(4) My aim was to try and use built-in and library code as much as possible rather than writing my own code (even if more efficient).
(5) Rrequires optimization (particularly in performance), it limits the input phrase to 30 characters, 
    but it will not run (=finish) within reasonable time up to that length ( 30-chars = 30! x 2^(30-1) different (potential) 
    multi-word anagrams ). Up to 9 characters input and it still finishes within reasonable time.
