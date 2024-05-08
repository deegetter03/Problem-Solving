#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

// METHOD1
class Solution
{
public:
  // Function to find the nodes that are common in both BST.
  void traverse(Node *root, map<int, int> &mpp)
  {
    if (!root)
      return;
    mpp[root->data]++;
    traverse(root->left, mpp);
    traverse(root->right, mpp);
  }

  vector<int> findCommon(Node *root1, Node *root2)
  {
    map<int, int> mpp;
    traverse(root1, mpp);
    traverse(root2, mpp);
    vector<int> ans;
    for (auto it : mpp)
    {
      if (it.second > 1)
        ans.push_back(it.first);
    }
    return ans;
  }
};

// METHOD2
class Solution
{
public:
  set<int> st;
  vector<int> ans;

  void solution(Node *root, int first)
  {
    if (!root)
      return;
    solution(root->left, first);

    if (first)
      st.insert(root->data);
    else if (st.find(root->data) != st.end())
      ans.push_back(root->data);

    solution(root->right, first);
  }

  vector<int> findCommon(Node *root1, Node *root2)
  {
    solution(root1, true);
    solution(root2, false);
    return ans;
  }
};