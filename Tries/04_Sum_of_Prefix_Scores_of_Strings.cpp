#include <bits/stdc++.h>
using namespace std;

//lc 2416
class Trie {
public:
    Trie* children[26] = {};
    bool isWord=false;
    int val=0;
    Trie() {}
    
    void insert(string word) {
        Trie* current = this;
        for(char ch: word){
            ch -='a';
            if(current->children[ch]==nullptr){
                current->children[ch] = new Trie();
            }
            current = current->children[ch];
            current->val++;
        }
        current->isWord = true;
    }
    
    int startsWith(string prefix) {
        Trie* current = this;
        int value=0;
        for(char ch:prefix){
            ch-='a';
            current = current->children[ch];
            value += current->val;
        }
        return value;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();
        for(string word: words)
            root->insert(word);
        vector<int> result;
        for(string word: words)
            result.push_back(root->startsWith(word));
        return result;
    }
};