#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXV = 505;
const int INF = 1000000000;
int n, G[MAXV][MAXV], cost[MAXV][MAXV];
int d[MAXV],c[MAXV],pre[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s){
    fill(d,d+MAXV,INF);
    fill(c,c+MAXV,INF);
    d[s] = 0;
    c[s] = 0;
    for (int i = 0; i < n; ++i) {
        pre[i] = i;
    }
    for(int i = 0; i<n; i++){
        int u = -1, MIN = INF;
        for (int j = 0; j < n; ++j) {
            if(vis[j]== false && d[j]<MIN){
                u=j;
                MIN = d[j];
            }
        }
        if(u == -1 )return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF ){
                if(d[u]+G[u][v]< d[v]){
                d[v] = d[u] + G[u][v];
                c[v] = c[u] + cost[u][v];
                pre[v] = u;
                } else if(d[u] + G[u][v] == d[v]){
                    if(c[u] + cost[u][v] < c[v]){
                        c[v] = c[u] + cost[u][v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}
void DFS(int v,int s){
    if(v==s){
        cout<<v<<" ";
        return;
    }
    DFS(pre[v],s);
    cout<<v<<" ";
}
int main() {
    int m,s,ed;
    fill(G[0],G[0]+MAXV*MAXV,INF);
    cin>>n>>m>>s>>ed;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        cin>>G[a][b]>>cost[a][b];
        G[b][a] = G[a][b];
        cost[b][a] = cost[a][b];
    }
    Dijkstra(s);
    printf("%d %d",d[ed],c[ed]);
  //  DFS(ed,s);

}