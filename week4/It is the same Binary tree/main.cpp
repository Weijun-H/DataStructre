#include <iostream>
#include <cstdio>
using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode{
    int data;
    Tree Left,Right;
    int flag = 0;
};

Tree NewNode(int x){
    Tree T = (Tree)malloc(sizeof(TreeNode));
    T->data = x;
    T->Left=T->Right=NULL;
    return T;
}
Tree Insert(Tree T,int x){
    if(!T)T=NewNode(x);
    else{
        if(T->data<x){
            T->Right = Insert(T->Right,x);
        } else{
            T->Left = Insert(T->Left,x);
        }
    }
    return T;
}

Tree MakeTree(int N){
    Tree T;
    int i,v;
    scanf("%d",&v);
    T = NewNode(v);
    for ( i = 1; i < N; ++i) {
        scanf("%d",&v);
        T = Insert(T,v);
    }
    return T;
}

int check(Tree T,int V){
    if(T->flag){
        if(V < T->data)return check(T->Left,V);
        else if(V > T->data)return  check(T->Right,V);
        else return 0;
    }else{
        if(V == T->data){
            T->flag = 1;
            return 1;
        }
        else return 0;
    }
}
int Judge(Tree T, int N) {
    //此处flag为1说明有错误，即两棵二叉搜索树不一样
    int i, V, flag = 0;

    scanf("%d", &V);
    if (V != T->data) flag = 1;	//有错误
    else T->flag = 1;			//被标记已经访问过
    for (i = 1; i < N; i++) {
        scanf("%d", &V);
        if ((!flag) && (!check(T, V))) flag = 1;
    }
    if (flag) return 0;
    else return 1;
}

void ResetT(Tree T){
    if(T->Left)ResetT(T->Left);
    if(T->Right)ResetT(T->Right);
    T->flag=0;
}

void FreeTree(Tree T){
    if(T->Left)FreeTree(T->Left);
    if(T->Right)FreeTree(T->Right);
    free(T);
}

int main() {
    int N, L, i;
    Tree T;

    scanf("%d", &N);
    while (N) {
        scanf("%d", &L);
        T = MakeTree(N);
        for (i = 0; i < L; i++) {
            if (Judge(T, N)) printf("Yes\n");
            else printf("No\n");
            ResetT(T);
        }
        FreeTree(T);
        scanf("%d", &N);
    }

    return 0;
}
