#include <bits/stdc++.h>
using namespace std;

//lc421
class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Solution {
public:
    void insertIntoTrieNode(TrieNode* root, int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int num : nums) {
            insertIntoTrieNode(root, num);
        }
        int maxXOR = 0;
        for (int num : nums) {
            TrieNode* node = root;
            int xor_val = 0;
            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;
                if (node->children[1 - bit] != nullptr) {
                    node = node->children[1 - bit];
                    xor_val += (1 << i);
                } else {
                    node = node->children[bit];
                }
            }
            maxXOR = max(maxXOR, xor_val);
        }
        return maxXOR;
    }
};