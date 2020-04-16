#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType search(List L,ElementType X,ElementType start,ElementType end){
    if(start>end)
        return NotFound;
    ElementType mid = (end+start)/2;
    if(L->Data[mid]==X)return mid;
    else if(L->Data[mid]>X)return search(L,X,start,mid-1);
    else return search(L,X,mid+1,end);
}
Position BinarySearch( List L, ElementType X ){
    return search(L,X,1,L->Last);
}

