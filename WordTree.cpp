#include "WordTree.h"
#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using namespace std;
WordTree::WordTree()
{
    m_root = NULL;
    m_uniqueWordCount = 0;
    m_wordCount = 0;
}

void WordTree::insert(string word, int line)
{
    m_root = insert(m_root, word, line);
}

WordNode* WordTree::insert(WordNode* root, string word, int line)
{
    if (root == NULL){
        root = new WordNode;
        root-> m_left = NULL;
        root-> m_right = NULL;
        root-> m_parent = NULL;
        root-> m_word = word;
        root-> m_count = 1;
        root-> m_lines.push_back(line);
        return root;
    }
    for(int i = 0; i < word.length() && i < root->m_word.length(); i++)
        if ((int) word[i] < (int) root->m_word[i]){
            root->m_left = insert(root->m_left, word, line);
            root->m_left->m_parent = root;
            break;
        }
        else if ((int) word[i] > (int) root->m_word[i]){
            root->m_right = insert(root->m_right, word, line);
            root->m_right->m_parent = root;
            break;
        }
        else if ((int) word[i] == (int) root->m_word[i] && i >= word.length() - 1 && i >= root->m_word.length() - 1){
            root->m_count ++;
            root->m_lines.push_back(line);
            return root;
        }
        else if(i >= word.length() -1){
            root->m_left = insert(root->m_left, word, line);
            root->m_left->m_parent = root;
            break;
            }
        else if( i > root->m_word.length() -1){
            root->m_right = insert(root->m_right, word, line);
            root->m_right->m_parent = root;
            break;
        }

    return root;
}

void WordTree::printTreeInOrder()
{
    printTreeInOrder(m_root);
}
void WordTree::printTreeInOrder(WordNode* root)
{
    if(root == NULL){
        return;
    }
        printTreeInOrder(root -> m_left);

        cout << root->m_word << " x " << root->m_count << endl;

        printTreeInOrder(root -> m_right);
}

int WordTree::countUniqueWords()
{
    countUniqueWords(m_root);
    return m_uniqueWordCount;

}
void WordTree::countUniqueWords(WordNode* root)
{
    if(root == NULL)
        return;

    countUniqueWords(root->m_left);

    m_uniqueWordCount ++;

    countUniqueWords(root->m_right);

}
int WordTree::countWords()
{
    countWords(m_root);
    return m_wordCount;

}
void WordTree::countWords(WordNode* root)
{
    if(root == NULL)
        return;

    countWords(root->m_left);

    m_wordCount += root->m_count;

    countWords(root->m_right);
}
string WordTree::lastWord()
{
    return lastWord(m_root);
}
string WordTree::lastWord(WordNode* root)
{
    if(root->m_right == NULL)
        return root->m_word;
    return lastWord(root->m_right);
}
string WordTree::firstWord()
{
    return firstWord(m_root);
}
string WordTree::firstWord(WordNode* root)
{
    if(root->m_left == NULL)
        return root->m_word;
    return firstWord(root->m_left);
}
vector<int> WordTree::wordLines(string word)
{
    return wordLines(m_root, word);
}
vector<int> WordTree::wordLines(WordNode* root, string word)
{
    for(int i = 0; i < word.length() && i < root->m_word.length(); i++)
        if ((int) word[i] == (int) root->m_word[i] && i >= word.length() - 1 && i >= root->m_word.length() - 1)
            return root->m_lines;
        else if(i >= word.length() - 1)
            return wordLines(root->m_left, word);
        else if(i >= root->m_word.length() - 1)
            return wordLines(root->m_right, word);
        else if ((int) word[i] < (int) root->m_word[i])
            return wordLines(root->m_left, word);
        else if ((int) word[i] > (int) root->m_word[i])
            return wordLines(root->m_right, word);
}
vector<string> WordTree::mostFrequent()
{
    m_mfSize = 1;
    mostFrequent(m_root);
    return m_mf;
}
void WordTree::mostFrequent(WordNode* root)
{
    if(root == NULL)
        return;
    mostFrequent(root->m_left);

    if(root->m_count == m_mfSize)
        m_mf.push_back(root->m_word);
    else if(root->m_count > m_mfSize){
        m_mf.clear();
        m_mf.push_back(root->m_word);
        m_mfSize = root->m_count;
    }

    mostFrequent(root->m_right);
}


