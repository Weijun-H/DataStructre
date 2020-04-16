#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1005;
int N,M;

void downAdjust(int low, int height,vector<int>&heap){
    int i = low, j = i*2;
    while (j <= height){
        if(j+1<=height && heap[j+1]<heap[j]){
            j += 1;
        }
        if(heap[j] < heap[i]){
            swap(heap[i],heap[j]);
            i = j;
            j = i*2;
        }else{
            break;
        }
    }
}
void createHeap(vector<int>&heap){
    for (int i = N/2; i >= 1; i--) {
        //downAdjust(i,N,heap);

    }
}
void printRoute(vector<int>heap, int index){
    while (index >= 1){
        cout<<heap[index];
        if(index!=1)cout<<" ";
        index /=2;
    }
}
int main(){
    cin>>N>>M;
    vector<int>heap(N+1);
    for (int i = 0; i < N; ++i) {
        cin>>heap[i+1];
    }
    createHeap(heap);
    for (int i = 0; i < M; ++i) {
        int index;
        cin>>index;
        printRoute(heap,index);
        if(i!=M-1)cout<<endl;
    }

}