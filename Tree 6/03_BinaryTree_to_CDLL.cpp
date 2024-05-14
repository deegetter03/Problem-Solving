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
    TreeNode *head = nullptr, *prev = nullptr;
    void inorder(TreeNode *root) {
        if(root == NULL) return;
        inorder(root->left);
        if(head == NULL) head = root;
        else{
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        inorder(root->right);
    }
    //Function to convert binary tree into circular doubly linked list.
    TreeNode *bTreeToCList(TreeNode *root)
    {
    inorder(root);
        head->left = prev;
        prev->right = head;
        return head;
    }
};