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
    vector <int> bottomView(TreeNode *root) {
        // Your Code Here
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* Treenode = q.front().first;
            int x = q.front().second;
            q.pop();
            mp[x]=Treenode->val;
            if(Treenode->left) q.push({Treenode->left, x-1});
            if(Treenode->right) q.push({Treenode->right, x+1});
        }
        vector<int> ans;
        for(auto it : mp) ans.push_back(it.second);
        return ans;
    }
};