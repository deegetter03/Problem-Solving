#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.lc653
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//METHOD1
//inorder,array,2point
class Solution {
public:
    void getIn(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;
        v.push_back(root->val);
        getIn(root->left, v);
        getIn(root->right, v);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> v;
        getIn(root, v);
        sort(v.begin(), v.end());
        int low = 0, high = v.size() - 1;
        while (low < high) {
            if (v[low] + v[high] == k) {
                return true;
            } else if (v[low] + v[high] < k) {
                low++;
            } else {
                high--;
            }
        }
        return false;
    }
};