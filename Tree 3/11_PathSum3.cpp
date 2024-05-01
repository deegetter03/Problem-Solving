#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.,lc437
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
    long long ans = 0;
    void pathfromroot(TreeNode* root, long long targetSum) {
        if (root == NULL) return;
        if (targetSum - root->val == 0) ans++;

        pathfromroot(root->left, targetSum - root->val);
        pathfromroot(root->right, targetSum - root->val);
    }

    int pathSum(TreeNode* root, long long targetSum) {
        if (root != NULL) {
            pathfromroot(root, targetSum);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ans;
    }
};