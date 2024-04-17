#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution{
  public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
       //Your code here
        int sum = 0;
        int level = 1;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()){
            int n = q.size();
            if (level % 2 != 0){
                for (int i = 0; i < n; i++){
                    Node *temp = q.front();
                    q.pop();
                    sum += temp->data;
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                }
            }
            else {
                for (int i = 0; i < n; i++) {
                    Node *temp = q.front();
                    q.pop();
                    sum -= temp->data;
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                }
            }
            level++;
        }
        return sum;
    }
};