#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
const int BORDER=50;
const double  ISLAND=15.0/2;
const int N=110;
struct node{
    double x,y;
};
node p[N];//记录鳄鱼的坐标 
bool vis[N];//标记重复 
int n;//输入鳄鱼的个数 
double JUMP;//007每次可以调的距离

bool FirstJump(int i){//第一次跳是否可以调到鳄鱼身上 
    return sqrt( p[i].x*p[i].x+p[i].y*p[i].y )<=JUMP+ISLAND;
}

bool Jump(int x,int y){//每一次跳（除第一次）是否可以到鳄鱼上 
    return sqrt( (p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)* ( p[x].y-p[y].y) )<=JUMP;
}

bool judge(int i){//判断007是否逃出 
    return (abs(p[i].x)>=50-JUMP||abs(p[i].y)>=50-JUMP);
}
bool DFS(int i){
    vis[i]=true;
    bool ans=false;
    if(judge(i))
        return true;
    for(int t=0;t<n;t++)
    {
        if(!vis[t]&&Jump(i,t))
            ans=DFS(t);
        if(ans)
            break;
    }
    return ans;
}
void Save007(){
    bool IsSave=false;
    for(int i=0;i<n;i++){//遍历每一点，把每种情况dfs一遍
        if(!vis[i]&&FirstJump(i)){
            IsSave=DFS(i);//如果其中有其中情况符合要求，直接退出
            if(IsSave)
                break;
        }
    }
    if(IsSave)
        puts("Yes");
    else
        puts("No");
}
int main() {

    cin >> n >> JUMP;
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    for (int i = 0; i < 110; i++)
        vis[i] = false;
    Save007();
    return 0;
}