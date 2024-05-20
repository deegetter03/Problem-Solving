#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    public:
    void getstore(TreeNode *root,map<int,int>&mpp){
        if(root==NULL) return;
        getstore(root->left,mpp);
        mpp[root->val]++;
        getstore(root->right,mpp);
    }
    
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    vector<int> merge(TreeNode *root1, TreeNode *root2)
    {
       vector<int>ans;
       map<int,int>mpp;
       getstore(root1,mpp);
       getstore(root2,mpp);
       for(auto it:mpp){
           for(int i=0;i<it.second;i++){
               ans.push_back(it.first);
           }
       }
       return ans;
    }
};