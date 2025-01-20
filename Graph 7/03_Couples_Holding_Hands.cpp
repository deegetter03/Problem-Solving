#include <bits/stdc++.h>
using namespace std;

//lc765
//METHOD 1 
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int count = 0;

        // This loop will decrement all odd numbers by 1
        for (int i = 0; i < row.size(); i++) {
            if (row[i] % 2 == 1) {
                row[i]--;
            }
        }

        // Now just traverse the vector, if couple already together, don't do
        // anything Otherwise just swap the neighbour with right partner
        for (int i = 0; i < row.size(); i = i + 2) {
            if (row[i] == row[i + 1]) {
                continue;
            } 
            else {
                // Find the partner
                for (int j = i + 2; j < row.size(); j++) {
                    if (row[i] == row[j]) {
                        swap(row[j], row[i + 1]);
                        break;
                    }
                }
                count++;
            }
        }
        return count;
    }
};

//METHOD 2
class Solution {
public:
    class disjoint{
        public:
            vector<int>par;
            vector<int>rank;
            disjoint(int n){
                par.resize(n+1,0);
                rank.resize(n+1,1);
                for(int i=0;i<=n;i++)par[i] = i;
            }
            int find_par(int node){
                if(node==par[node])return node;
                return par[node] = find_par(par[node]);
            }
            bool union_by_rank(int a, int b){
                int para = find_par(a);
                int parb = find_par(b);
                if(para==parb)return true;
                if(rank[para]<rank[parb]){
                    rank[parb]+=rank[para];
                    par[para] = parb;
                    
                }
                else{
                    rank[para]+=rank[parb];
                    par[parb] = para;
                   
                }
                return false;
            }
            int find_size(int num){
                int par_num = find_par(num);
                int temp = rank[par_num];
                rank[par_num]=2;
                return temp;
            }
    };
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        int n=row.size();
        disjoint ds(n);
        for(int i=0;i<n;i+=2)ds.union_by_rank(i,i+1);
        for(int i=0;i<n;i+=2)ds.union_by_rank(row[i],row[i+1]);
        for(int i=0;i<n;i++){
            ans+=(ds.find_size(i)/2-1);
        }
        return ans;
    }
};