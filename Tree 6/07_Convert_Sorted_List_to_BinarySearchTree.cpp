#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.lc109
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* getmid(vector<int>arr, int low, int high){
        if(low > high) return NULL;
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = getmid(arr,low,((low + high)/2)-1);
        root->right = getmid(arr,((low + high)/2)+1,high);
        return root;
    }

    TreeNode* sortedListToBST(TreeNode* head) {
        vector<int>nodes;
        while(head){
            nodes.push_back(head->val);
            head = head->right;
        }
        return getmid(nodes,0,nodes.size()-1);
    }
};