#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
#define MAX 10000
#define INFINITY 65535
int N, M, A[MAX][MAX], ECT;  //ETC--earliest completion time
int getMax( int arr[] ) {
    int max = 0;
    for(int i = 0; i < N; i++)
        if( max < arr[i] )
            max = arr[i];
    return max;
}

int TopSort(){
    int V, cnt = 0, Indegree[MAX] = {0}, EarliestTime[MAX] = {0};
    queue<int> q;
    //计算各结点的入度
    for( int i = 0; i < N; i++ )
        for( int j = 0; j < N; j++ )
            if( A[i][j] != INFINITY )
                Indegree[j]++;	//对于有向边<i,j>累计终点j的入度
    //入度为0的入队
    for( int i = 0; i < N; i++ )
        if( Indegree[i] == 0 )
            q.push(i);
    while( !q.empty() ) {
        V = q.front();
        q.pop();
        cnt++;
        for( int j = 0; j < N; j++ )
            if( A[V][j] != INFINITY ) {  //<V, j>有有向边
                if( EarliestTime[V] + A[V][j] > EarliestTime[j] ){ //如果 V的最早完成时间 + j所需时间 > j的最早完成时间
                    EarliestTime[j] = EarliestTime[V] + A[V][j];
                }
                if( --Indegree[j] == 0 )  //去掉V后，如果j的入度为0
                    q.push(j);
            }
    }
    ECT = getMax(EarliestTime); //最早完成时间应是所有元素中最大的
    if( cnt != N ) return 0;	//如果没有取出所有元素，说明图中有回路
    else return 1;
}
int main() {
    int a, b;
    scanf("%d %d", &N, &M);
    //初始化图的边
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = INFINITY;
    //read
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        scanf("%d", &A[a][b]);
    }
    if (!TopSort())
        printf("Impossible\n");
    else
        printf("%d\n", ECT);
    system("pause");
    return 0;
}