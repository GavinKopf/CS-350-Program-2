/*
* Program puts words in a binary search tree
*
* @author Gavin Kopf
* @version 13.7
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <bits/stdc++.h>
#include "WordTree.h"
#include "WordNode.h"
using namespace std;

int main()
{
    fstream file;
    string line, word, filename;
    int lineNumber = 0;
    filename = "TestLab2.txt";
    file.open(filename.c_str());
    WordTree * tree = new WordTree;
    while (getline(file, line)) {
        lineNumber += 1;
        stringstream ss( line );
        while ( ss >> word ) {
            word.erase(remove(word.begin(), word.end(), ','), word.end());
            word.erase(remove(word.begin(), word.end(), '.'), word.end());
            word.erase(remove(word.begin(), word.end(), ';'), word.end());
            word.erase(remove(word.begin(), word.end(), '-'), word.end());
            transform (word.begin(), word.end(), word.begin(), ::tolower);
            tree->insert(word,lineNumber);
        }
    }

    tree->printTreeInOrder();

    cout << "There are " << tree->countWords() << " words in the file" << endl;
    cout << "There are " << tree->countUniqueWords() << " unique words in the file"
    << endl;
    cout << "Alphabetical first word: " << tree->firstWord() << endl;
    cout << "Alphabetical last word: " << tree->lastWord() << endl;

    vector<int> occurrences;
    occurrences = tree->wordLines("computer");

    cout << "The word computer appears on the following lines: ";
    for (unsigned i=0; i<occurrences.size(); i++){
    cout << ' ' << occurrences[i];
    }
    cout << endl;

    vector<string> frequentWords;
    frequentWords = tree->mostFrequent();
    cout << "The most frequent word(s): ";
    for (unsigned i=0; i<frequentWords.size(); i++){
    cout << frequentWords[i] << ' ';
    }

    return 0;
}
