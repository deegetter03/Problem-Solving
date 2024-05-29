#include <bits/stdc++.h>
using namespace std;

//lc1442
//METHOD 1
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre(n, 0);
        int ans = 0;
        vector<int>& xor_arr = arr;
        for (int i = 1; i < n; i++) {
            xor_arr[i] ^= xor_arr[i - 1];
        }
        for (int i = 0; i < n - 1; i++) {
            pre.back() = (xor_arr.back()) ? 0 : 1;
            ans += pre.back();
            for (int j = n - 2; j > i; j--) {
                pre[j] = 0;
                if (xor_arr[j] == 0) {
                    pre[j] = 1;
                }
                pre[j] += pre[j + 1];
                ans += pre[j];
            }
            for (int k = i + 1; k < n; k++) {
                xor_arr[k] ^= xor_arr[i];
            }
        }
        return ans;
    }
};

//METHOD 2
class TrieNode {
public:
    int numOfIndex;
    int sumOfIndex;
    TrieNode* child[2];

    TrieNode() : numOfIndex(0), sumOfIndex(0) {
        child[0] = NULL;
        child[1] = NULL;
    }
};
class Solution {
public:
    void addNumber(TrieNode* root, int num, int idx) {
        for (int i = 31; i >= 0; i--) {

            int bit = 1 & (num >> i);

            if (root->child[bit] == NULL) {
                root->child[bit] = new TrieNode();
            }
            root = root->child[bit];
        }
        root->sumOfIndex += idx;
        root->numOfIndex++;
    }
    int calculateIndexPair(TrieNode* root, int num, int idx) {
        for (int i = 31; i >= 0; i--) {
            int bit = 1 & (num >> i);

            if (root->child[bit] == NULL) {
                return 0;
            }
            root = root->child[bit];
        }
        return (((root->numOfIndex) * idx) - (root->sumOfIndex));
    }
    int countTriplets(vector<int>& arr) {
        long long ans = 0;
        int XOR = 0;
        TrieNode* root = new TrieNode();

        for (int i = 0; i < arr.size(); i++) {
            addNumber(root, XOR, i);
            XOR ^= arr[i];
            ans = (ans + calculateIndexPair(root, XOR, i)) % 1000000007;
        }
        return ans;
    }
};