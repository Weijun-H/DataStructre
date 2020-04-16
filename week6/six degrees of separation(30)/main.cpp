#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1005;
int graph[MAXN][MAXN];
bool vis[MAXN] = {false};
int N,M;
int  cnt = 0;

void DFS(int u,int deep){
    vis[u] = true;
    for (int i = 1; i <= N; ++i) {
        if(vis[i] == false && graph[u][i] == 1 ){
            if( deep+1 <= 6) {
                cnt++;
                vis[i] = true;
                DFS(i, deep + 1);
            }
            else{
                break;
            }
        }
    }
}
void DFSTravse(){


    for (int i = 1; i <= N; ++i) {
        cnt = 0;
        DFS(i,0);
        cnt++;
        printf("%d: %.2f%%\n",i,float(cnt)/float(N)*100);
        for (int i = 1; i <= N; ++i) {
            vis[i] = false;
        }
    }


}
int main() {
    cin>>N>>M;
    for (int i = 0; i < M; ++i) {
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }
    DFSTravse();

}