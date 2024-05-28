#include <bits/stdc++.h>
using namespace std;

// METHOD 1
class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> ans;
        vector<string> temp;
        string check = "";

        for (int i = 0; i < s.length(); i++)
        {
            unordered_map<string, int> mp;
            check = check + (s[i]);
            for (int j = 0; j < n; j++)
            {
                if (contact[j].find(check) == 0 && mp.find(contact[j]) == mp.end())
                {
                    temp.push_back(contact[j]);
                    mp[contact[j]] = i;
                }
            }
            if (temp.size() == 0)
            {
                temp.push_back("0");
            }
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};

// METHOD 2
class Node
{
public:
    char ch;
    bool isend;
    vector<Node *> next;

    Node(char c)
    {
        ch = c;
        isend = false;
        next.resize(26, NULL);
    }
};

class Solution
{
public:
    void record(Node *root, vector<string> &res, string cur)
    {
        // Recursive code to add all eligible child node char to result
        if (root)
        {
            if (root->isend)
                res.push_back(cur + root->ch);
            for (int j = 0; j < 26; j++)
            {
                if (root->next[j] != NULL)
                    record(root->next[j], res, cur + root->ch);
            }
        }
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> res(s.size());
        Node *root = new Node(s[0]);
        char start = s[0];

        // Insert all contacts in TRIE
        for (int i = 0; i < n; i++)
        {
            string ts = contact[i];
            if (ts[0] == start)
            {
                Node *temp = root;
                for (int j = 1; j < contact[i].length(); j++)
                {
                    if (temp->next[(int)ts[j] - 'a'] == NULL)
                    {
                        temp->next[(int)ts[j] - 'a'] = new Node(ts[j]);
                    }
                    temp = temp->next[(int)ts[j] - 'a'];
                }
                temp->isend = true;
            }
        }
        Node *temp = root;
        string cur = "";
        // Call recursive function for each length of 's'
        for (int i = 0; i < s.size(); i++)
        {
            if (i != 0)
                temp = temp->next[(int)s[i] - 'a'];
            record(temp, res[i], cur);
            if (res[i].empty() || temp == NULL)
            {
                for (; i < s.size(); i++)
                {
                    res[i].push_back("0");
                }
                break;
            }
            cur += temp->ch;
        }
        return res;
    }
};