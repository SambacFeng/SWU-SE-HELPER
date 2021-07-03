#include <iostream>
using namespace std;

// 打印数组
void printArr(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
    {
        cout << *(arr + i) << " ";
    }
    cout << "\n"
         << endl;
}

/*******************************************************************************
 * 冒泡排序（Bubble Sort）
        它重复地走访过要排序的元素，依次比较相邻两个元素，如果它们的顺序错误就把他们
    调换过来，直到没有元素再需要交换，排序完成。
********************************************************************************/
int *BubbleSort(int array[], int len)
{
    int temp;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (array[j + 1] < array[j])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}

/*******************************************************************************
 * 选择排序（Selection Sort）
       第一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，
    然后再从剩余的未排序元素中寻找到最小（大）元素，然后放到已排序的序列的末尾。
********************************************************************************/
int *SelectionSort(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int minIndex = i;
        for (int j = i; j < len; j++)
        {
            if (array[j] < array[minIndex]) //找到最小的数
                minIndex = j;               //将最小数的索引保存
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
    return array;
}

/*******************************************************************************
 * 插入排序（Insertion Sort）
       将一个记录插入到已经排好序的有序表中。
********************************************************************************/
int *InsertionSort(int array[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int current = array[i + 1]; // 待归位的数
        int preIndex = i;           // 待归位的前面的一个数
        // 利用逐个比较的方式将待归位的数归位。
        while (preIndex >= 0 && current < array[preIndex])
        {
            array[preIndex + 1] = array[preIndex];
            preIndex--;
        }
        array[preIndex + 1] = current; // 找到了正确的位置，进行归位
    }
    return array;
}

/*******************************************************************************
 * 快速排序（Quick Sort）
       将待排数组分隔成独立的两部分，其中一部分记录的关键字均比另一部分的关键字小，则
    可分别对这两部分记录继续进行排序，以达到整个序列有序。
********************************************************************************/
// 快速排序核心算法——Partition：
int Partition(int array[], int start, int end)
{
    int i = start, j = end + 1;
    // 将start暂存在x里面，顺便作为基准元素
    int x = array[start];
    // 将小于x的元素交换到左边区域，将大于x的元素交换到右边区域
    while (true)
    {
        while (array[++i] < x && i < end)
            ; // 找到小于基准元素的第一个数
        while (array[--j] > x)
            ; // 找到大于基准元素的第一个数
        if (i >= j)
            break; // 小于基准元素的第一个数在大于基准元素的第一个数的右边，说明划分完毕
        swap(array[i], array[j]);
    }
    array[start] = array[j]; // 将中间位置的元素放在第一个
    array[j] = x;            // 将刚才暂存在x中的start（基准元素放在中间）
    return j;                // 返回中间位置索引
}

int *QuickSort(int array[], int start, int end)
{
    int q = Partition(array, start, end);
    if (q > start)
        QuickSort(array, start, q - 1);
    if (q < end)
        QuickSort(array, q + 1, end);
    return array;
}

/*******************************************************************************
 * 归并排序（Merge Sort）
       就是把数组分成更小的数组,合并的时候再排序
********************************************************************************/
int *MergeSort(int array[], int len)
{
    int *a = array;
    int *b = new int[len];
    // 每次循环的规模（seg）翻倍
    for (int seg = 1; seg < len; seg += seg)
    {
        for (int start = 0; start < len; start += seg + seg)
        {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2) // 合并两个数组
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1) // 数组2已经合并完了，开始合并剩余的数组1
                b[k++] = a[start1++];
            while (start2 < end2) // 数组1已经合并完了，开始合并剩余的数组2
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if (a != array)
    {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    return b;
}

// // 递归框架
// int tmpArray[];
// void MergeSort(int array[], int left, int right)
// {
//     if (left < right) // 至少两个元素
//     {
//         int i = (left + right) / 2; // 取中点
//         MergeSort(array, left, i);
//         MergeSort(array, i + 1, right);
//         Merge(array, tmpArray, left, i, right); // 合并到数组tmpArray
//         Copy(array, tmpArray, left, right);     // 将tmpArray中的数据复制回array
//     }
// }

/*******************************************************************************
 * 希尔排序（Shell Sort）
       是插入排序的一种又称“缩小增量排序”。比较相隔较远距离（称为增量）的数，使得数
    移动时能跨过多个元素，则进行一次比较就可能消除多个元素交换。
********************************************************************************/
int *ShellSort(int array[], int len)
{
    int h = 1;
    while (h < len / 3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < len; i++)
        {
            for (int j = i; j >= h && array[j] < array[j - h]; j -= h)
            {
                swap(array[j], array[j - h]);
            }
        }
        h = h / 3;
    }
    return array;
}

/*******************************************************************************
 * 计数排序（Counting Sort）
       是对于给定的输入序列中的每一个元素x，确定该序列中值小于x的元素的个数。
********************************************************************************/
int *CountingSort(int array[], int len)
{
    int i, j, k;
    int max = -10000;
    for (i = 0; i < len; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    int *count_arr = new int[max];
    int *sorted_arr = new int[len];
    for (k = 0; k < 100; k++)
        count_arr[k] = 0;
    for (i = 0; i < len; i++)
        count_arr[array[i]]++;
    for (k = 1; k < 100; k++)
        count_arr[k] += count_arr[k - 1];
    for (j = len; j > 0; j--)
        sorted_arr[--count_arr[array[j - 1]]] = array[j - 1];
    return sorted_arr;
}

int main()
{
    // C++的数组是地址传递，所以要复制多组原始乱序数组
    int arr1[13] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9};
    int arr2[13] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9};
    int arr3[13] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9};
    int arr4[13] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9};
    int arr5[13] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9};
    int arr6[13] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9};
    int arr7[13] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9};
    int len = sizeof(arr1) / sizeof(int);

    cout << "Bubble Sort:" << endl;
    BubbleSort(arr1, len);
    printArr(arr1, len);

    cout << "Select Sort:" << endl;
    SelectionSort(arr2, len);
    printArr(arr2, len);

    cout << "Insertion Sort:" << endl;
    InsertionSort(arr3, len);
    printArr(arr3, len);

    cout << "Quick Sort:" << endl;
    QuickSort(arr4, 0, 12);
    printArr(arr4, len);

    cout << "Merge Sort:" << endl;
    MergeSort(arr5, len);
    printArr(arr5, len);

    cout << "Shell Sort:" << endl;
    ShellSort(arr6, len);
    printArr(arr6, len);

    cout << "Counting Sort:" << endl;
    int *sortArr;
    sortArr = CountingSort(arr7, len);
    printArr(sortArr, len);
}