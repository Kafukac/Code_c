#include <iostream>

// 函数用于计算数组元素的总和
int sumArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 1; i < size; i++)
    { // 这里存在逻辑错误
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = sumArray(arr, size);
    std::cout << "数组元素的总和是: " << result << std::endl;
    return 0;
}
