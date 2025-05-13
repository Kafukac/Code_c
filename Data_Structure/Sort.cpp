#include <iostream>  // 输入输出流
#include <vector>    // 动态数组容器
#include <cstdlib>   // 标准库（包含随机数生成函数）
#include <ctime>     // 时间相关函数（用于随机数种子）
#include <algorithm> // 标准算法库（用于验证排序结果）
using namespace std; // 使用标准命名空间

// 函数声明
void bubbleSort(vector<int> &arr);
void selectionSort(vector<int> &arr);
void insertionSort(vector<int> &arr);
void quickSort(vector<int> &arr, int left, int right);
void mergeSort(vector<int> &arr, int left, int right);
void merge(vector<int> &arr, int left, int mid, int right);
void heapSort(vector<int> &arr);
void heapify(vector<int> &arr, int n, int i);
void printArray(const vector<int> &arr);
bool isSorted(const vector<int> &arr);
vector<int> generateRandomArray(int size, int min, int max);

int main()
{
    srand(time(0)); // 初始化随机数种子

    while (true)
    {
        cout << "\n===== 排序算法测试程序 =====" << endl;
        cout << "1. 冒泡排序" << endl;
        cout << "2. 选择排序" << endl;
        cout << "3. 插入排序" << endl;
        cout << "4. 快速排序" << endl;
        cout << "5. 归并排序" << endl;
        cout << "6. 堆排序" << endl;
        cout << "7. 退出" << endl;
        cout << "请选择排序算法: ";

        int choice;
        cin >> choice;

        if (choice == 7)
            break;

        cout << "请输入数组大小: ";
        int size;
        cin >> size;

        vector<int> arr = generateRandomArray(size, 1, 1000);
        vector<int> original = arr; // 保存原始数组用于验证

        cout << "\n排序前的数组: ";
        printArray(arr);

        clock_t start = clock();

        switch (choice)
        {
        case 1:
            bubbleSort(arr);
            break;
        case 2:
            selectionSort(arr);
            break;
        case 3:
            insertionSort(arr);
            break;
        case 4:
            quickSort(arr, 0, arr.size() - 1);
            break;
        case 5:
            mergeSort(arr, 0, arr.size() - 1);
            break;
        case 6:
            heapSort(arr);
            break;
        default:
            cout << "无效选择!" << endl;
            continue;
        }

        clock_t end = clock();
        double time = double(end - start) / CLOCKS_PER_SEC * 1000; // 转换为毫秒

        cout << "排序后的数组: ";
        printArray(arr);

        cout << "排序耗时: " << time << " 毫秒" << endl;
        cout << "排序结果验证: " << (isSorted(arr) ? "正确" : "错误") << endl;

        // 验证与标准库排序结果是否一致
        vector<int> stdSorted = original;
        sort(stdSorted.begin(), stdSorted.end());
        cout << "与std::sort结果比较: " << (arr == stdSorted ? "相同" : "不同") << endl;
    }

    return 0;
}

// 冒泡排序实现
void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break; // 优化：如果某轮未交换，说明已排序
    }
}

// 选择排序实现
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            swap(arr[i], arr[minIdx]);
        }
    }
}

// 插入排序实现
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            int tmp = arr[i];
            int j;
            for (j = i - 1; j >= 0 && arr[j] > tmp; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = tmp;
        }
    }
}

// 快速排序实现
void quickSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[right]);
        int partitionIndex = i + 1;

        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
}

// 归并排序实现
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 堆排序实现
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // 构建最大堆
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 一个个交换元素
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// 辅助函数：打印数组
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// 辅助函数：验证数组是否已排序
bool isSorted(const vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

// 辅助函数：生成随机数组
vector<int> generateRandomArray(int size, int min, int max)
{
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
    return arr;
}