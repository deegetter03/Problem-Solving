#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.,lc112
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        targetSum -= root->val;
        if (!root->left && !root->right)
            return targetSum == 0;

        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};