#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
struct Node{
    int Rtree=-1,Ltree=-1;
};

int main() {
    int n,s;
    cin>>n;
    vector<Node>tree(n);
    int check[n];
    for (int k = 0; k < n; ++k) {
        check[k]=-1;
    }
    for (int i = 0; i < n ; ++i) {
        char l,r;
        cin>>l>>r;
        if(l != '-'){
            tree[i].Ltree=l-'0';
            check[l-'0']=1;
        }
        if(r != '-'){
            tree[i].Rtree=r-'0';
            check[r-'0']=1;
        }
    }
    for (int j = 0; j < n; ++j) {
        if(check[j]==-1){
            s=j;
            break;
        }
    }

    queue<int>q;
    q.push(s);
    vector<int>ans;
    while (!q.empty()){
        int t;
        t = q.front();
        q.pop();
        if(tree[t].Ltree==-1&&tree[t].Rtree==-1){
            ans.push_back(t);
        }
        if(tree[t].Ltree!=-1)q.push(tree[t].Ltree);
        if(tree[t].Rtree!=-1)q.push(tree[t].Rtree);
    }
    for (int i =0;i<ans.size();i++) {
        cout<<ans[i];
        if(i!=ans.size()-1){
            printf(" ");
        }
    }
}