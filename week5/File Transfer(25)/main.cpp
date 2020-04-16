#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int father[10005];
int findFather(int x){
    if(x == father[x])return x;
    else {
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}
void Union(int a,int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA!=faB){
        father[faA]=faB;
    }
}
int main(){
    for (int i = 0; i < 10005; ++i) {
        father[i]=i;
    }
    int N;
    cin>>N;
    char op;
    cin>>op;
    while (op!='S'){
        int a,b;
        cin>>a>>b;

        if(op=='C'){
            if(findFather(a)==findFather(b)){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
        else if(op=='I') {
            Union(a,b);
        }
        cin>>op;
    }
    int count = 0;
    for (int i = 1; i <= N ; ++i) {
        if(father[i]==i){count++;}
    }
    if(count==1)printf("The network is connected.");
    else printf("There are %d components.",count);
}