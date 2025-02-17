#ifndef WORDNODE_H
#define WORDNODE_H
#include<iostream>
#include<vector>

using namespace std;

class WordNode
{
    public:
        WordNode();
        string m_word;
        int m_count;
        vector<int> m_lines;
        WordNode* m_left;
        WordNode* m_right;
        WordNode* m_parent;


    protected:

    private:
        WordNode* m_root;
};

#endif // WORDNODE_H
