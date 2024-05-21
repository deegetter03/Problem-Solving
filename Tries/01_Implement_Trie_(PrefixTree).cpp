#include <bits/stdc++.h>
using namespace std;

//lc208

class Trie {
public:
    Trie* children[26];
    bool isEnd;
    Trie() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isEnd = false;
    }

    void insert(string word) {
        Trie* current = this;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (current->children[ch - 'a'] == NULL) {
                current->children[ch - 'a'] = new Trie();
            }
            current = current->children[ch - 'a'];
        }
        current->isEnd = true;
    }

    bool search(string word) {
        Trie* current = this;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (current->children[ch - 'a'] == NULL) {
                return false;
            }
            current = current->children[ch - 'a'];
        }
        if (current->isEnd == true)
            return true;
        return false;
    }

    bool startsWith(string prefix) {
        Trie* current = this;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            if (current->children[ch - 'a'] == NULL) {
                return false;
            }
            current = current->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */