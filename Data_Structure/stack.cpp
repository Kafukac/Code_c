#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

template <typename T>
class SeqStack
{
private:
    T data[MAX_SIZE];
    int top;

public:
    SeqStack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void push(T item)
    {
        if (isFull())
        {
            cout << "Stack is full, cannot push." << endl;
            return;
        }
        data[++top] = item;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, cannot pop." << endl;
            return T();
        }
        return data[top--];
    }

    T peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, no top element." << endl;
            return T();
        }
        return data[top];
    }
};

#define MaxSize 10 // 定义栈中元素的最大个数
typedef struct
{
    ElemType data[MaxSize]; // 静态数组存放栈中元素
    int top0;               // 0号栈栈顶指针
    int top1;               // 1号栈栈顶指针
} ShStack;

// 初始化栈
void InitSqStack(ShStack &S)
{
    S.top0 = -1; // 初始化栈顶指针
    S.top1 = MaxSize;
}

struct Linknode
{
    int data;
    Linknode *next;
} Linknode, *LiStack;

typedef Linknode *Node;
