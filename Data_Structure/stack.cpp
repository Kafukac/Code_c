#define MaxSize 10 // 定义栈中元素的最大个数

typedef struct
{
    ElemType data[MaxSize]; // 静态数组存放栈中元素
    int top;                // 栈顶元素
} SqStack;

void testStack()
{
    SqStack S; // 声明一个顺序栈(分配空间)
               // 连续的存储空间大小为 MaxSize*sizeof(ElemType)
}
