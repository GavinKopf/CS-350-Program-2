#ifndef WORDTREE_H
#define WORDTREE_H
#include <iostream>
#include <vector>
#include "WordNode.h"

using namespace std;
class WordTree
{
    public:
        WordTree();
        void insert(string, int);
        void printTreeInOrder();
        int countUniqueWords();
        int countWords();
        string lastWord();
        string firstWord();
        vector<int> wordLines(string);
        vector<string> mostFrequent();
    protected:
        WordNode* insert(WordNode*, string, int);
        void printTreeInOrder(WordNode*);
        void countUniqueWords(WordNode*);
        void countWords(WordNode*);
        string lastWord(WordNode*);
        string firstWord(WordNode*);
        vector<int> wordLines(WordNode*, string);
        void mostFrequent(WordNode*);
    private:
        WordNode* m_root;
        int m_uniqueWordCount;
        int m_wordCount;
        vector<string> m_mf;
        int m_mfSize;


};

#endif // WORDTREE_H
