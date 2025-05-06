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
bool ListInsert(SeqList &l, int i, int e)
{
    if (i < 1 || i > l.length + 1)
    {
        return false;
    }
    if (l.length > MaxSize)
    {
        return false;
    }
    for (int j = L.length)
}