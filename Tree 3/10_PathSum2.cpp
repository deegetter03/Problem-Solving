#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.,lc113
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
    vector<vector<int>> ans;
    vector<int> a;
    void check(TreeNode* root, int targetSum) {
        if(!root) return;
        a.push_back(root->val);
        targetSum-=root->val;

        if(!root->left && !root->right) {
            if(targetSum==0)
                ans.push_back(a);
        }
        else
        {
            check(root->left,targetSum);
            check(root->right,targetSum);
        }    
        a.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        check(root,targetSum);
        return ans;
    }
};