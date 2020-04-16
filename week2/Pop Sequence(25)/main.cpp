#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;
int main() {
    int capacity,length,n;
    cin>>capacity>>length>>n;

    for (int i = 0; i < n; ++i) {

        stack<int>v;
        queue<int>t;

        int temp;
        for (int j = 1; j <= length ; ++j) {
            cin>>temp;
            t.push(temp);
        }

        for (int j = 1; j <= length ; ++j) {
            v.push(j);
            while (!v.empty()&&v.top()==t.front() && v.size()<=capacity){
                t.pop();
                v.pop();
            }
        }
        if(v.empty()){
            printf("YES");
        } else{
            printf("NO");
        }
        if(i!=n-1)printf("\n");
    }
}