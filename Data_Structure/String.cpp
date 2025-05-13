#include <iostream>
#include <cstring>
using namespace std;

// --------------- 定长顺序存储表示 ---------------
#define MAXLEN 255

typedef struct
{
    char ch[MAXLEN]; // 存储串的一维数组
    int length;      // 当前串的长度
} SString;

// 初始化串
void InitString(SString &S)
{
    S.length = 0;
}

// 生成一个其值等于chars的串T
bool StrAssign(SString &T, const char *chars)
{
    int len = strlen(chars);
    if (len > MAXLEN)
        return false;
    strcpy(T.ch, chars);
    T.length = len;
    return true;
}

// 复制串
bool StrCopy(SString &T, SString S)
{
    if (S.length > MAXLEN)
        return false;
    strcpy(T.ch, S.ch);
    T.length = S.length;
    return true;
}

// 判断串是否为空
bool StrEmpty(SString S)
{
    return S.length == 0;
}

// 比较两个串的大小
int StrCompare(SString S, SString T)
{
    return strcmp(S.ch, T.ch);
}

// 求串的长度
int StrLength(SString S)
{
    return S.length;
}

// 清空串
void ClearString(SString &S)
{
    S.length = 0;
}

// 连接两个串
bool Concat(SString &T, SString S1, SString S2)
{
    if (S1.length + S2.length > MAXLEN)
        return false;
    strcpy(T.ch, S1.ch);
    strcat(T.ch, S2.ch);
    T.length = S1.length + S2.length;
    return true;
}

// 求子串
bool SubString(SString &Sub, SString S, int pos, int len)
{
    if (pos < 1 || pos > S.length || len < 0 || pos + len - 1 > S.length)
        return false;
    for (int i = 0; i < len; i++)
        Sub.ch[i] = S.ch[pos - 1 + i];
    Sub.length = len;
    return true;
}

// 朴素模式匹配算法
int Index(SString S, SString T, int pos)
{
    if (pos < 1 || pos > S.length)
        return 0;
    int i = pos - 1, j = 0;
    while (i < S.length && j < T.length)
    {
        if (S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j == T.length)
        return i - T.length + 1;
    else
        return 0;
}

// 输出串
void PrintString(SString S)
{
    for (int i = 0; i < S.length; i++)
        cout << S.ch[i];
    cout << endl;
}

// --------------- 堆分配存储表示 ---------------
typedef struct
{
    char *ch;   // 按串长分配存储区，ch指向串的基地址
    int length; // 串的当前长度
} HString;

// 初始化堆分配串
void InitHString(HString &S)
{
    S.ch = NULL;
    S.length = 0;
}

// 生成一个其值等于chars的串T
bool StrAssign(HString &T, const char *chars)
{
    if (T.ch)
        delete[] T.ch; // 释放原空间
    int len = strlen(chars);
    if (!len)
    {
        T.ch = NULL;
        T.length = 0;
        return true;
    }
    T.ch = new char[len + 1];
    if (!T.ch)
        return false;
    strcpy(T.ch, chars);
    T.length = len;
    return true;
}

// --------------- KMP算法 ---------------
// 求模式串T的next函数值并存入数组next
void get_next(SString T, int next[])
{
    int i = 1, j = 0;
    next[1] = 0;
    while (i < T.length)
    {
        if (j == 0 || T.ch[i - 1] == T.ch[j - 1])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

// KMP模式匹配算法
int Index_KMP(SString S, SString T, int pos)
{
    int i = pos - 1, j = 0;
    int *next = new int[T.length + 1];
    get_next(T, next);
    while (i < S.length && j < T.length)
    {
        if (j == 0 || S.ch[i] == T.ch[j])
        {
            i++;
            j++;
        }
        else
            j = next[j + 1] - 1;
    }
    delete[] next;
    if (j == T.length)
        return i - T.length + 1;
    else
        return 0;
}

// --------------- 测试代码 ---------------
int main()
{
    // 测试定长顺序存储串
    SString S, T;
    InitString(S);
    InitString(T);

    StrAssign(S, "hello world");
    cout << "S: ";
    PrintString(S);
    cout << "Length of S: " << StrLength(S) << endl;

    SubString(T, S, 7, 5);
    cout << "Substring T of S from pos 7 with length 5: ";
    PrintString(T);

    SString P;
    InitString(P);
    StrAssign(P, "world");
    cout << "Position of P in S: " << Index(S, P, 1) << endl;

    // 测试KMP算法
    SString S1, T1;
    InitString(S1);
    InitString(T1);
    StrAssign(S1, "ababcabcacbab");
    StrAssign(T1, "abcac");
    cout << "Position of T1 in S1 (KMP): " << Index_KMP(S1, T1, 1) << endl;

    return 0;
}