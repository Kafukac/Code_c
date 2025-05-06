// #include <iostream>
// using namespace std;

// class SeqList {
// private:
//     int* data;       // Pointer to dynamically allocated array
//     int capacity;    // Maximum capacity of the list
//     int size;        // Current size of the list

// public:
//     // Constructor
//     SeqList(int initialCapacity = 10) {
//         capacity = initialCapacity;
//         size = 0;
//         data = new int[capacity];
//     }

//     // Destructor
//     ~SeqList() {
//         delete[] data;
//     }

//     // Add an element to the end of the list
//     void append(int value) {
//         if (size == capacity) {
//             resize();
//         }
//         data[size++] = value;
//     }

//     // Insert an element at a specific position
//     void insert(int index, int value) {
//         if (index < 0 || index > size) {
//             cout << "Index out of bounds!" << endl;
//             return;
//         }
//         if (size == capacity) {
//             resize();
//         }
//         for (int i = size; i > index; --i) {
//             data[i] = data[i - 1];
//         }
//         data[index] = value;
//         size++;
//     }

//     // Remove an element at a specific position
//     void remove(int index) {
//         if (index < 0 || index >= size) {
//             cout << "Index out of bounds!" << endl;
//             return;
//         }
//         for (int i = index; i < size - 1; ++i) {
//             data[i] = data[i + 1];
//         }
//         size--;
//     }

//     // Get an element at a specific position
//     int get(int index) const {
//         if (index < 0 || index >= size) {
//             cout << "Index out of bounds!" << endl;
//             return -1;
//         }
//         return data[index];
//     }

//     // Print the list
//     void print() const {
//         for (int i = 0; i < size; ++i) {
//             cout << data[i] << " ";
//         }
//         cout << endl;
//     }

// private:
//     // Resize the array when capacity is reached
//     void resize() {
//         capacity *= 2;
//         int* newData = new int[capacity];
//         for (int i = 0; i < size; ++i) {
//             newData[i] = data[i];
//         }
//         delete[] data;
//         data = newData;
//     }
// };

// int main() {
//     SeqList list;

//     list.append(10);
//     list.append(20);
//     list.append(30);
//     list.print();

//     list.insert(1, 15);
//     list.print();

//     list.remove(2);
//     list.print();

//     cout << "Element at index 1: " << list.get(1) << endl;

//     return 0;
// }

#include <iostream>
#include <stdio.h>
#include <stdlib.h> //malloc free 头文件
#define InitSize 10

typedef struct
{
    int *data; // 指示动态分配数组的指针
    int length;
    int MaxSize;
} SeqList;

// 初始化
void InitList(SeqList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    if (L.data == NULL)
    {
        std::cout << "内存分配失败" << std::endl;
        exit(1); // 退出程序
    }
    L.length = 0;
    L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len)
{
    int *p = L.data; // 指向原来的数组
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i]; //
    }
    L.MaxSize = L.MaxSize + len; // 增加长度
    free(L.data);                // 释放原来的内存
}
int main(void)
{
    SeqList L;
    InitList(L);
    IncreaseSize(L, 5);
    return 0;
}

// 顺序表的基本操作
//  1. 插入操作
int MaxSize;
bool ListInsert(SeqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
    {
        return false;
    }
    if (L.length > MaxSize)
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 删除操作
bool ListDelete(SeqList &L, int i, int e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = L.length; j >= i; j--)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return false;
}

// 按位查找
#define MaxSize 10 // 定义最大长度
using ElemType = double;
typedef struct
{
    ElemType data[MaxSize]; // 用静态的“数组”存放数据元素
    int Length;             // 顺序表的当前长度
} SqList;                   // 顺序表的类型定义

ElemType GetElem(SqList L, int i)
{
    // ...判断i的值是否合法
    return L.data[i - 1]; // 注意是i-1
}

// 按值查找
int locateElem(SeqList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (e == L.data[i])
        {
            return i + 1;
        }
    }
}

// 线性表的链式表示
// 单链表的定义
typedef struct LNode
{
    ElemType data;      // 数据域
    struct LNode *next; // 指针域、
} LNode, *LinkList;

// 带头结点
// 初始化一个单链表
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
    }
    L->next = NULL;
    return true;
}

void test()
{
    LinkList L;
    InitList(L);
}

// 是否为空
bool Empty(LinkList L)
{
    if (L->next == NULL)
    {
        return true;
    }
    else
        return false;
}

// 在第i个位置插入元素e
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    LNode *p;  // 指针p指向当前扫描到的结点
    int j = 0; // 当前p指向的是第几个结点
    p = L;     // L指向头结点，头结点是第0个结点（不存数据）
    // 循环找到第i-1个节点
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        return false;
    }
    // 在第i-1个结点后插入新结点
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
}

// 后插
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InsertNextNode(LNode *p, ElemType e)
{
    if (p == NULL)
    {
        return false;
    }

    LNode *s = (LNode *)malloc(sizeof(LNode));
    // 某些情况下分配失败，比如内存不足
    if (s == NULL)
        return false;
    s->data = e; // 用结点s保存数据元素e
    s->next = p->next;
    p->next = s; // 将结点s连到p之后

    return true;
} // 平均时间复杂度 = O(1)

// 有了后插操作，那么在第i个位置上插入指定元素e的代码可以改成：
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;

    LNode *p;  // 指针p指向当前扫描到的结点
    int j = 0; // 当前p指向的是第几个结点
    p = L;     // L指向头结点，头结点是第0个结点（不存数据）

    // 循环找到第i-1个结点
    while (p != NULL && j < i - 1)
    {                // 如果i>length, p最后会等于NULL
        p = p->next; // p指向下一个结点
        j++;
    }

    return InsertNextNode(p, e);
}

// 前插
// 前插操作：在p结点之前插入元素e
bool InsertPriorNode(LNode *p, ElemType e)
{
    if (p == NULL)
        return false;

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL) // 内存分配失败
        return false;

    // 重点来了！
    s->next = p->next;
    p->next = s;       // 新结点s连到p之后
    s->data = p->data; // 将p中元素复制到s
    p->data = e;       // p中元素覆盖为e

    return true;
} // 时间复杂度为O(1)

// 按位删除节点
bool ListDelete(LinkList &L, int i, ElemType e)
{
    if (i < 1)
        return false;
    LNode *p;
    int j = 0;
    p = L;

    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }

    if (p == NULL)
        return false;
    if (p->next == NULL) // 第i-1个结点之后已无其他结点
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
}

// 1.头插法建立单链表（平均时间复杂度O(n)）
LinkList List_HeadInsert(LinkList &L)
{ // 逆向建立单链表
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode)); // 建立头结点
    L->next = NULL;                      // 初始为空链表,这步不能少！

    scanf("%d", &x); // 输入要插入的结点的值
    while (x != 9999)
    {                                       // 输入9999表结束
        s = (LNode *)malloc(sizeof(LNode)); // 创建新结点
        s->data = x;
        s->next = L->next;
        L->next = s; // 将新结点插入表中，L为头指针
        scanf("%d", &x);
    }
    return L;
}

// 尾插法建立单链表（时间复杂度O（n））
LinkList List_TailInsert(LinkList &L)
{                                        // 正向建立单链表
    int x;                               // 设ElemType为整型int
    L = (LinkList)malloc(sizeof(LNode)); // 建立头结点(初始化空表)
    LNode *s, *r = L;                    // r为表尾指针
    scanf("%d", &x);                     // 输入要插入的结点的值
    while (x != 9999)
    { // 输入9999表结束
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s; // r指针指向新的表尾结点
        scanf("%d", &x);
    }
    r->next = NULL; // 尾结点指针置空
    return L;
}

// 链表的逆置：
LNode *Inverse(LNode *L)
{
    LNode *p, *q;
    p = L->next;    // p指针指向第一个结点
    L->next = NULL; // 头结点指向NULL

    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = L->next;
        L->next = q;
    }
    return L;

    // 双链表
    typedef struct DNode
    {
        ElemType data;
        struct DNode *prior, *next;
    } DNode, *DLinkList;

    // 初始化
    typedef struct DNode
    {                               // 定义双链表结点类型
        ElemType data;              // 数据域
        struct DNode *prior, *next; // 前驱和后继指针
    } DNode, *Dlinklist;

    // 初始化双链表
    bool InitDLinkList(Dlinklist & L)
    {
        L = (DNode *)malloc(sizeof(DNode)); // 分配一个头结点
        if (L == NULL)                      // 内存不足，分配失败
            return false;

        L->prior = NULL; // 头结点的prior指针永远指向NULL
        L->next = NULL;  // 头结点之后暂时还没有结点
        return true;
    }

    void testDLinkList()
    {
        // 初始化双链表
        DLinklist L;      // 定义指向头结点的指针L
        InitDLinkList(L); // 申请一片空间用于存放头结点，指针L指向这个头结点
        //...
    }

    // 判断双链表是否为空
    bool Empty(DLinklist L)
    {
        if (L->next == NULL) // 判断头结点的next指针是否为空
            return true;
        else
            return false;
    }

    // 后插操作

    bool InsertNextDNode(DNode * p, DNode * s)
    {                               // 将结点 *s 插入到结点 *p之后
        if (p == NULL || s == NULL) // 非法参数
            return false;

        s->next = p->next;
        if (p->next != NULL) // p不是最后一个结点=p有后继结点
            p->next->prior = s;
        s->prior = p;
        p->next = s;

        return true;
    }

    // 删除p结点的后继结点
    bool DeleteNextDNode(DNode * p)
    {
        if (p == NULL)
            return false;
        DNode *q = p->next; // 找到p的后继结点q
        if (q == NULL)
            return false; // p没有后继结点;
        p->next = q->next;
        if (q->next != NULL) // q结点不是最后一个结点
            q->next->prior = p;
        free(q);

        return true;
    }

    // 销毁一个双链表
    bool DestroyList(DLinklist & L)
    {
        // 循环释放各个数据结点
        while (L->next != NULL)
        {
            DeleteNextDNode(L); // 删除头结点的后继结点
            free(L);            // 释放头结点
            L = NULL;           // 头指针指向NULL
        }
    }

    while (p != NULL)
    {
        // 对结点p做相应处理，eg打印
        p = p->prior;
    }

    while (p != NULL)
    {
        // 对结点p做相应处理，eg打印
        p = p->next;
    }

    // 循环单链表
    typedef struct LNode
    {
        ElemType data;
        struct LNode *next;
    } DNode, *Linklist;

    / 初始化一个循环单链表 bool InitList(LinkList & L)
    {
        L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点
        if (L == NULL)                      // 内存不足，分配失败
            return false;
        L->next = L; // 头结点next指针指向头结点
        return true;
    }

    // 判断循环单链表是否为空（终止条件为p或p->next是否等于头指针）
    bool Empty(LinkList L)
    {
        if (L->next == L)
            return true; // 为空
        else
            return false;
    }

    // 判断结点p是否为循环单链表的表尾结点
    bool isTail(LinkList L, LNode * p)
    {
        if (p->next == L)
            return true;
        else
            return false;
    }

    // 循环双链表
    typedef struct DNode
    {
        ElemType data;
        struct DNode *prior, *next;
    } DNode, *DLinklist;

    // 初始化空的循环双链表
    bool InitDLinkList(DLinklist & L)
    {
        L = (DNode *)malloc(sizeof(DNode)); // 分配一个头结点
        if (L == NULL)                      // 内存不足，分配失败
            return false;
        L->prior = L; // 头结点的prior指向头结点
        L->next = L;  // 头结点的next指向头结点
    }

    void testDLinkList()
    {
        // 初始化循环单链表
        DLinklist L;
        InitDLinkList(L);
        //...
    }

    // 判断循环双链表是否为空
    bool Empty(DLinklist L)
    {
        if (L->next == L)
            return true;
        else
            return false;
    }

    // 判断结点p是否为循环双链表的表尾结点
    bool isTail(DLinklist L, DNode * p)
    {
        if (p->next == L)
            return true;
        else
            return false;
    }
