#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.lc230
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//METHOD1:
//inorder se
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        return arr[k - 1];
    }
};

//METHOD2
//count,inorder traversal
class Solution {
public:
    void inorder(TreeNode* root, int &count, int &result, int k){
        if(root == NULL) return;
        //inorder = LNR
        inorder(root->left, count, result, k);
        count++;
        if(count == k){
            result = root->val;
            return;
        }
        inorder(root->right, count, result, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;        
        int result;
        inorder(root, count, result, k);
        return result;
    }
};