#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int graph[15][15];
bool visited[15] = {false};
int N,E;

void DFS(int u){
    cout<<u<<" ";
    visited[u] = true;
    for (int i = 0; i < N; ++i) {
        if(visited[i] == false && graph[u][i] != 0){
            DFS(i);
        }
    }
}

void DFSTrave(){
    for (int u = 0; u < N; ++u) {
        if(visited[u] == false){
        cout<<"{ ";
        DFS(u);
        cout<<"}"<<endl;
        }
    }
}

void BFS(int u){
    queue<int>q;
    q.push(u);
    visited[u] = true;
    cout<<u<<" ";
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int i = 0; i < N; ++i) {
            if(visited[i] == false && graph[u][i] != 0){
                q.push(i);
                visited[i] = true;
                cout<<i<<" ";
            }
        }
    }
}

void BFSTrave(){
    for (int i = 0; i < N; ++i) {
        if(visited[i] == false){
            cout<<"{ ";
            BFS(i);
            cout<<"}"<<endl;        }
    }
}

int main() {
    cin>>N>>E;
    for (int i = 0; i < E; ++i) {
        int a, b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    DFSTrave();
    for (int i = 0; i < N ; ++i) {
        visited[i] = false;
    }
    BFSTrave();
}