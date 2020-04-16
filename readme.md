

### 前言

系统学习数据结构

课程地址：https://www.icourse163.org/learn/ZJU-93001

## 一、基本概念

### 1.什么是数据结构

#### 1.1其他定义

- 数据结构是数据对象，以及存在于该对象的实例和组成实例的数据元素之间的各种联系。这些联系可以通过定义相关的函数来给出。 ——Sartaj Sahni 《数据结构、算法与应用》
- 数据结构是 ADT（Abstract Data Type，数据抽象类型）的物理实现。 ——Clifford A.Shaffer 《数据结构与算法分析》
- 数据结构（data structure）是计算机中存储、组织数据的方式。通常情况下，精心选择的数据结构可以带来最优效率的算法。 ——中文维基百科

#### 1.2解决问题方法的效率

- 跟数组的组织方式有关

- 跟空间的利用效率有关

- 跟算法的巧妙程度有关

  ##### 计算运行时间

  Q:函数单次运行时间过短？

  A:让被测函数重复运行多次，取平均时间

计算被测函数运行时间模版

```c++
#include<stdio>
#include<time.h>
clock_t start,end;
double duration;
int main(){
  start = clock();
  MyFunction();
  stop = clock;
  duration = (double(stop - start)/CLK_TCK);
  return
}
```

#### 1.3 最终定义

- 数据对象在计算机中的组织方式
  - 逻辑结构
  - 物理存储结构
- 数据对象必定与一系列加在其上的操作相关联
- 完成这些操作所用的方法就是算法

#### 1.4 抽象数据类型（Abstract Data Type）

- 数据类型

  - 数据对象集
  - 数据集合相关联的操作集

- 抽象：描述数据类型的方法不依赖于具体实现

  - 与存放数据的机器无关
  - 与数据存储的物理结构无关
  - 与实现操作的算法和编程语言均无关

  抽象不关心具体实现细节，关心的是宏观程度上把握程序的整体架构

### 2.什么是算法

#### 2.1.定义

- 一个有限指令集
- 接受一些输入
- 一定在有限步骤之后终止

- 每一条指令必须
  - 有充分明确的目标，不可以有歧义
  - 计算机能处理范围内
  - 描述应不依赖于任何一种计算机语言以及具体的实现手段

#### 2.2 描述算法的手段

1. 空间复杂度 S(n)

   根据算法写成的程序在执行时**占用存储空间的长度**

2. 时间复杂度 T(n)

   根据算法写成的程序在执行时**耗费的时间的长度**

递归函数每递归一次，都需要将parent process的寄存器信息压入栈中![image-20200217152312735](/Users/huangweijun/Library/Application Support/typora-user-images/image-20200217152312735.png)

#### 2.3 评价

在分析一般算法的效率时，常常关注

1. 最坏情况复杂度 $ T_{worst}(n) $

2. 平均情况复杂度 $T_{avg}(n) $

$$
T_{arg}(n) \le T_{worst}(n)
$$

一般情况下更多关注的是最坏情况复杂度

#### 2.4 复杂度的渐进表达

- $T(n)=O(f(n))$ 表示存在常数$C>0，n_0>0 $使得当 $n \ge n_0$时有$T(n)≤C⋅f(n)$, 即 $O(f(n))$表示 $f(n)$是 $T(n) $的某种上界
- $T(n)=Ω(g(n))$ 表示存在常数$C>0，n_0>0 $使得当 $n \ge n_0$时有$T(n)≤C⋅g(n)$, 即 $Ω(g(n))$表示 $f(n)$是 $T(n) $的某种下界
- $T(n)=θ(h(n))$ 表示存在常数$C>0，n_0>0 $使得当 $n \ge n_0$时有$T(n)≤C⋅h(n)$, 即 $θ(f(n))$表示 $f(n)$是 $T(n) $的上界也是下界

#### 2.5 复杂度分析小窍门

1. 若两段算法分别有复杂度 $T_1(n)=O(f1(n))$和$T_2(n) = O(f_2(n))$，则

- $T_1(n)+T_2(n)=max(O(f_1(n)),O(f_2(n)))$
- $T_1(n)\times T_2(n)=O(f_1(n))\times O(f_2(n))$

2. 若$T(n)$是关于$n$的$k$阶多项式，那么$T(n)=\theta(n^k)$
3. 一个 for 循环的时间复杂度等于循环次数乘以循环体代码的复杂度

4. if-else 结构的复杂度取决于 if 的条件判断复杂度和两个分枝部分的复杂度，总体复杂度取三者中最大

### 3. 最大子列集问题

题目：给定N个整数的序列$\{A_1,A_2,A_3,...,A_N\}$求函数$f(i,j)=max\{0,\sum_{k=0}^j A_k \}$

##### 算法一（暴力法）：

```C
int MaxSubseqSum1(int A[],int N){
  int ThisSum, MaxSum = 0;
  int i, j, k;
  for(i=0, i<N; i++){/*子列左端*/
    for(j=i; j<N; j++){/*子列右端*/
      ThisSum = 0;
      for(k=i; k<=j; k++)
        ThisSum += A[k];
      if(ThisSum > MaxSum)
        MaxSum = ThisSum;
    }
  }
  return MaxSum;
}
```

时间复杂度：$O(N^3)$

改进方法：每次计算ThisSum是不必重新计算，只需与后续元素直接相加

##### 算法二（改进暴力法）：

```c
int MaxSubseqSum2(int A[],int N){
  int ThisSum, MaxSum = 0;
  int i, j, k;
  for(i=0, i<N; i++){/*子列左端*/
    for(j=i; j<N; j++){/*子列右端*/
      ThisSum += A[j];
      if(ThisSum > MaxSum)
        MaxSum = ThisSum;
    }
  }
  return MaxSum;
}
```

时间复杂度：$O(N^2)$

##### 算法三（分而治之）：

```c
 int Max3( int A, int B, int C )
{ /* 返回3个整数中的最大值 */
    return A > B ? A > C ? A : C : B > C ? B : C;
}
 
int DivideAndConquer( int List[], int left, int right )
{ /* 分治法求List[left]到List[right]的最大子列和 */
    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/
 
    int LeftBorderSum, RightBorderSum;
    int center, i;
 
    if( left == right )  { /* 递归的终止条件，子列只有1个数字 */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }
 
    /* 下面是"分"的过程 */
    center = ( left + right ) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );
 
    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */
 
    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */
 
    /* 下面返回"治"的结果 */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}
 
int MaxSubseqSum3( int List[], int N )
{ /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer( List, 0, N-1 );
}
```

时间复杂度：$O(NlogN)$
$$
T(N) = 2T(N/2)+cN, \qquad T(1)=O(1)\\
=2[2T(N/2^2)+c N/2]+cN\\
其中N/2^k=1
$$

##### 算法四（在线处理）：

```c
int MaxSubseqSum4(int A[],int N){
  int ThisSum, MaxSum = 0;
  int i, j, k;
  for(i=0, i<N; i++){
    ThisSum += A[i];/*向右累加*/
    if(ThisSum > MaxSum)
      MaxSum = ThisSum;
    else if(ThisSum<0)/*当前子列和为负*/
      ThisSum = 0;/*则不可能使后面的部分和增大，抛弃*/
  }
  return MaxSum;
}
```

时间复杂度：$O(N)$

## 二、线性结构

### 1.线性表及其实现

#### 1. 1什么是线性表

 “线性表”：由同类型数据元素构成有序序列的线性结构

- 表中元素个数称为线性表的**长度**
- 线性表没有元素时，称为**空表**
- 表起始位置称为**表头**，表结束位置称**表尾**

#### 1.2线性表的抽象数据类型描述

- 类型名称：线性表（List）

- 数据对象集：线性表是 $n(≥0)$个元素构成的有序序列$(a_1,a_2,...,a_n)$

- 操作集：线性表 $L\in List$ ，整数 i 表示位置，元素 $X\in ElementType$

- 线性表基本操作主要有：
  - `List MakeEmpty()`： 初始化一个空线性表 L
  - `ElementType FindKth(int K,List L)`：根据位序 K，返回相应元素
  - `int Find(ElementType X,List L)`：在线性表 L 中查找 X 的第一次出现位置
  - `void Insert(ElementType X,int i,List L)`：在位序 i 前插入一个新元素 X
  - `void Delete(int i,List L)`：删除指定位序 i 的元素
  - `int Length(List L)`：返回线性表 L 的长度 n

#### 1.3存储实现方法

##### 1.3.1顺序存储实现

```C
typedf struct LNode *List;
struct LNode{
  ElementType Data[MAXSIZE];
  int Last;
};
struct LNode L;
List PtrL;

/*initail*/
List MakeEmpty(){
  List PtrL;
  PtrL = (List)malloc(sizeof(struct LNode));
  PtrL->Last = -1;
  return PtrL;
}

/*Find element*/
int Find(ElementType X,List PtrL){
  int i = 0;
  while(i <= PtrL->Last && PtrL->Data[i]!=X)i++;
  if(i > PtrL->Last) return -1;
  else return i;
}

/*insert element*/
void Insert(ElementType X,int i,List PtrL){
  int j;
  if(PtrL->Last == MAXSIZE-1){
    printf("Full");
    return;
  }
  if(i<1 || i>PtrL->Last+2){
    printf("unfair position");
    return;
  }
  for(j=PtrL->Last; j>=i;j--){
    PtrL->Data[j+1] = PtrL->Data[j];
  }
  PtrL->Data[i-1] = X;
  PtrL->Last++;
  return;
}
/*平均移动次数为n/2*/
/*平均时间性能是O（n）*/

void Delete(int i,List PtrL){
  int j;
  if(i<1 || i>PtrL->Last+1){
    printf("不存在第%d个元素",i);
    return;
  }
  for(j=i; j<=PtrL->Last; j++){
    PtrL->Data[j-1] = PtrL->Data[j];
  }
  PtrL->Last--;
}
/*平均移动次数为(n-1)/2*/
/*平均时间性能是O（n）*/
```

##### 1.3.1链式存储实现

 不要求逻辑上相邻的两个元素物理上也相邻，通过"链"建立起数据之间的逻辑关系

- 插入、删除不需要移动数据元素，只需要修改"链"

```C
typedef int ElementType; // ElementType 可定义为任意类型
typedef struct LNode *List;
struct LNode{
	ElementType Data;   //数据域 
	List Next;   // 下一个链表的地址 
}; 
List L;

List MakeEmpty(); //初始化链表 
int Length(List L);  // 以遍历链表的方法求链表长度 
List FindKth(int K,List L);  // 按序号查找 
List Find(ElementType X,List L);  // 按值查找 
List Insert(ElementType X,int i,List L);  //将 X 插入到第 i-1(i>0) 个结点之后 
List Delete(int i,List L); // 删除第 i(i>0) 个结点 
void Print(List L); // 输出链表元素 

// 初始化链表 
List MakeEmpty(){
	List L = (List)malloc(sizeof(struct LNode));
	L = NULL;
	return L;
}

//求表长 
int Length(List L){
	List p = L;
	int len=0;
	while(p){  // 当 p 不为空 
		p = p->Next;
		len++;
	}
	return len;
} 

// 按序查找 
List FindKth(int K,List L){
	List p = L;
	int i = 1;  //从 1 开始 
	while(p && i<K){
		p = p->Next;
		i++;
	}
	if(i == K)    // 找到了 
		return p;
	else    // 未找到 
		return NULL;
} 

// 按值查找  
List Find(ElementType X,List L){
	List p = L;
	while(p && p->Data!=X)
		p = p->Next;
	// 找到了，返回 p
	// 未找到，返回 NULL，此时 p 等于 NULL 
	return p;   
} 

/* 插入
1. 用 s 指向一个新的结点
2. 用 p 指向链表的第 i-1 个结点 
3. s->Next = p->Next，将 s 的下一个结点指向 p 的下一个结点 
4. p->Next = s，将 p 的下一结点改为 s   */
List Insert(ElementType X,int i,List L){
	List p,s;
	if(i == 1){     // 新结点插入在表头 
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = L;
		return s;     //插入的结点为头结点 
	}
	p = FindKth(i-1,L);   // 找到第 i-1 个结点
	if(!p){   // 第 i-1 个结点不存在 
		printf("结点错误");
		return NULL;
	}else{
		s = (List)malloc(sizeof(struct LNode));
		s->Data = X;
		s->Next = p->Next;   //将 s 的下一个结点指向 p 的下一个结点 
		p->Next = s;   // 将 p 的下一结点改为 s
		return L;
	}
}

/* 删除
1. 用 p 指向链表的第 i-1 个结点 
2. 用 s 指向要被删除的的第 i 个结点
3. p->Next = s->Next，p 指针指向 s 后面
4. free(s)，释放空间 
*/
List Delete(int i,List L){
	List p,s;
	if(i==1){   //如果要删除头结点 
		s = L;
		if(L)   // 如果不为空 
			L = L->Next;
		else
			return NULL;
		free(s);   // 释放被删除结点 
		return L; 
	}
	p = FindKth(i-1,L);    // 查找第 i-1 个结点
	if(!p || !(p->Next)){     // 第 i-1 个或第 i 个结点不存在 
		printf("结点错误");
		return NULL;
	}else{
		s = p->Next;    // s 指向第 i 个结点 
		p->Next = s->Next;  //从链表删除 
		free(s);  // 释放被删除结点 
		return L;
	}
}

// 输出链表元素 
void Print(List L){
	List t;
	int flag = 1;
	printf("当前链表为：");
	for(t = L;t;t =t->Next){
		printf("%d  ",t->Data);
		flag = 0;
	}
	if(flag)
		printf("NULL");
	printf("\n"); 
}

int main(){
	L = MakeEmpty();
	Print(L);
	L = Insert(11,1,L);
	L = Insert(25,1,L);
	L = Insert(33,2,L);
	L = Insert(77,3,L);
	Print(L);
	printf("当前链表长度为：%d\n",Length(L));
	printf("此时链表中第二个结点的值是：%d\n",FindKth(2,L)->Data);
	printf("查找22是否在该链表中：");
	if(Find(22,L))
		printf("是！\n");
	else
		printf("否！\n");
	printf("查找33是否在该链表中：");
	if(Find(33,L))
		printf("是！\n");
	else
		printf("否！\n");
	L = Delete(1,L);
	L = Delete(3,L);
	printf("----------删除后-----\n"); 
	Print(L);
	return 0;
} 
```

#### 1.4广义表与多重链表

##### 1.4.1广义表

- 广义表是线性表的推广，广义表属于多重链表
- 对于线性表而言，n个元素都是基本的单元素
- 广义表中，这些元素不仅可以是单元素也可以是另一个广义表

```C
typedef struct GNode *GList;
struct Gnode{
  int Tag;/*标示域：区分是单元素还是广义表*/
  union {
    ElementType Data;
    GList SubList;
  }URegion;
  GList Next;
}
```

##### 1.4.2多重链表

- 多重链表中的结点的指针域会有多个
- 但是包含两个指针域的链表并不一定是多重链表，比如`双向链表`
- 广泛用途：树、图
- 处理稀疏矩阵（十字链表）

### 2.堆栈

#### 2.1什么是堆栈

堆栈（Stack）：具有一定操作约束的线性表

- 只在一端（栈顶，Top）做插入、删除
- 插入数据：入栈（Push）
- 删除数据：出栈（Pop）
- 后入先出：Last In First Out（LIFO）

#### 2.2堆栈的抽象数据类型描述

- 类型名称：堆栈（Stack）

- 数据对象集：一个有 0 个或多个元素的有穷线性表

- 操作集：长度为 MaxSize 的堆栈$ S ∈ Stack$，堆栈元素 $item ∈ ElementType$

堆栈的基本操作主要有：

- `Stack CreateStack(int MaxSize)`：生成空堆栈，其最大长度为 MaxSize
- `int IsFull(Stack S,int MaxSize)`：判断堆栈 S 是否已满
- `void Push(Stack S,ElementType item)`：将元素 item 压入堆栈
- `int IsEmpty(Stack S)`：判断堆栈 S 是否为空
- `ElementType Pop(Stack S)`：删除并返回栈顶元素

#### 2.3存储实现

##### 2.3.1栈的顺序存储实现

```C
#defind MaxSize <储存数据元素的最大个数>
typedef struct SNode *Stack;
struct SNode{
  ElementType Data[MaxSize];
  int Top;
}

void Push(Stack PtrS, ElementType item){
  if(Ptr->Top == MaxSize-1){
    printf("堆栈满");
    return;
  }else{
    PtrS->Data[++(PtrS->Top)] = item;
    return;
  }
}

ElementType Pop(Stack PtrS){
  if(PtrS->Top == -1){
    printf("堆栈空");
    return ERROR;
  }else{
    return (PtrS->Data[(Ptr->Top)--])
  }
}
```



> 请用一个数组实现两个堆栈，要求最大地利用数组空间，使数组只要有空间入栈操作就可以成功

```C
#defind MaxSize <储存数据元素的最大个数>
typedef struct SNode *Stack;
struct SNode{
  ElementType Data[MaxSize];
  int Top1 = -1;
  int Top2 = MaxSize;
}S;

void Push(struct DStack *PtrS, ElementType item, int Tag){
  if(PtrS->Top2 - PtrS->Top1 == 1{
    printf("堆栈满");
  }
  if(Tag == 1){
    PtrS->Data[++(PtrS->Top1)] = item;
  }else{
    PtrS->Data[--(PtrS->Top2)] = item;
  }
}     

ElementType Pop(struct DStack *PtrS, int Tag){
  if(Tag == 1){
    if(PtrS->Top1 == -1){
      printf("堆栈1空");
    }else {
      return PtrS->Data[(PtrS->Top1)--];
    }
  }else{
    if(PtrS->Top2 == -MaxSize){
      printf("堆栈2空");
    }else {
      return PtrS->Data[(PtrS->Top2)++];
  }
}
```

##### 2.3.2栈的链式存储实现

 栈的链式存储结构实际上就是一个单链表，叫做链栈。插入和删除操作只能在链栈的栈顶进行

栈顶指针Top应该在链表的首部

```C
typedef struct SNode *Stack;
struct SNode{
  ElementType Data;
  struct SNode *Next;
};

Stack CreateStack(){
  Stack S;
  S = (Stack)malloc(sizeof(struct Snode));
  S->Next = NULL;
  return S;
}

int IsEmpty(Stack S){
  return (S->Next == NULL);
}

void Push(ElementType item, Stack S){
  struct SNode *TmpCell;
  TmpCell = (struct SNode*)malloc(sizeof(struct SNode));
  TmpCell->Element = item;
  TmpCell->Next = s->Next;
  S->Next = TmpCell;
}

ElementType Pop(Stack S){
  struct SNode *FirstCell;
  ElementType TopElem;
  if(IsEmpty(S)){
    printf("堆栈空");
    return NULL;
  }else{
    FirstCell = S->Next;
    S->Next = FirstCell->Next;
    TopElem = FirstCell->Element;
    free(FirstCell);
    return TopElem;
  }
}
```

#### 2.4堆栈的应用

- 中缀表达式求值
- 函数调用及递归实现
- 深度优先搜索
- 回溯算法

