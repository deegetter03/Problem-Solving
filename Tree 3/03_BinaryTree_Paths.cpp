#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
};


class Solution {
public:
    void path(TreeNode* root, vector<string>& ans, string temp, int flag) {
        if (root == NULL) return;
        if (flag == 0) {
            string val = to_string(root->val);
            temp += val;
            flag = 1;
        } 
        else {
            string val = to_string(root->val);
            temp += "->" + val;
        }

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(temp);
            return;
        }
        path(root->left, ans, temp, flag);
        path(root->right, ans, temp, flag);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        path(root, ans, "", 0);
        return ans;
    }
};