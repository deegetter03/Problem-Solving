#include <bits/stdc++.h>
using namespace std;

//lc 3093

class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        int index = -1;
        int length = INT_MAX;
    };

    void insert(TrieNode* node, const string& word, int index, int depth) {
        if (depth == word.size()) {
            // At each node make sure to select the smallest length
            // If equal length choose the smallest index
            int sz = word.length();
            if (sz < node->length) {
                node->length = sz;
                node->index = index;
            } else if (sz == node->length) {
                if (node->index == -1)
                    node->index = index;
                else
                    node->index = min(node->index, index);
            }
            return;
        }

        int ch = word[depth] - 'a';
        if (!node->children[ch])
            node->children[ch] = new TrieNode();

        // Recursively start from last char
        insert(node->children[ch], word, index, depth + 1);

        // At each node make sure to select the smallest length
        // If equal length choose the smallest index
        if (node->children[ch]->length < node->length) {
            node->length = node->children[ch]->length;
            node->index = node->children[ch]->index;
        } else if ((node->children[ch]->length == node->length) &&
                   (node->children[ch]->index < node->index)) {
            node->index = node->children[ch]->index;
        }

        // cout<<word<<" "<<depth<<" "<<(node->index)<<"
        // "<<(node->length)<<endl;
    }

    int query(TrieNode* root, const string& word) {
        TrieNode* node = root;
        int ans = -1;
        for (int i = 0; i < word.size(); ++i) {
            int ch = word[i] - 'a';
            node = node->children[ch];

            if (!node)
                return ans;
            ans = node->index;
        }
        return ans;
    }

    void insert(TrieNode* node, string& x, int i) { insert(node, x, i, 0); }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();

        for (int i = 0; i < wordsContainer.size(); i++) {
            // Dummy added to take care of common suffix being empty
            wordsContainer[i].push_back('a');
            reverse(wordsContainer[i].begin(), wordsContainer[i].end());
            insert(root, wordsContainer[i], i);
        }

        int n = wordsQuery.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            // Dummy added to take care of common suffix being empty
            wordsQuery[i].push_back('a');
            reverse(wordsQuery[i].begin(), wordsQuery[i].end());

            ans[i] = query(root, wordsQuery[i]);
        }

        return ans;
    }
};