#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

// METHOD1
int findCeil(Node *root, int input)
{
  if (root == NULL)
    return -1;
  int ceil = -1;
  while (root)
  {
    if (root->data == input) // input BST me hai toh
      return input;
    else if (root->data < input)
      root = root->right;
    else
    {
      ceil = root->data;
      root = root->left;
    }
  }
  return ceil;
}

// METHOD2
void Inorder(Node *root, vector<int> &ans)
{
  if (root == NULL)
    return;

  Inorder(root->left, ans);
  ans.push_back(root->data);
  Inorder(root->right, ans);
}

int findCeil(Node *root, int input)
{
  if (root == NULL) return -1;

  vector<int> ans;
  Inorder(root, ans);
  int n = ans.size();
  int low = 0, high = n - 1;
  int ceil = -1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (ans[mid] == input)
      return input;

    else if (ans[mid] > input)
    {
      ceil = ans[mid];
      high = mid - 1;
    }
    else  low = mid + 1;
  }
  return ceil;
}