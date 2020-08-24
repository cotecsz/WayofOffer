//
// Created by Yang Shuangzhen on 2020/8/24.
//

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*
 * 快速排序：分而治之（侧重分解，简化合并）
 *      1. 划分：选取最后一个元素作为主元（pivot），使用双指针 i, j分别指向开始的 -1 0元素
 *      2. 对于每个元素判断其是否小于主元，如果小于主元，则交换 A[i], A[j]
 *      3. 遍历完成后，将主元放至中间位置
 *
 *  时间复杂度分析：
 *      T(n) = T(k) + T(n-k+1) + n
 *
 *      最好情况：T(n) = T(n/2) + T(n/2) + n, 时间复杂度为 O(nlogn)
 *      最坏情况：T(n) = T(n-1) + n, 复杂度为 O(n^2)
 *          解决最坏情况：使用随机选择主元的方式，复杂度为 O(nlogn)
 *  空间复杂度：O(1)
 *
 *  快速排序 V.S. 归并排序
 *      1. 划分：快速排序划分以任意比例，而归并排序将数组划分为相等的两部分
 *      2. 时间复杂度：快速排序 O(nlogn) 最坏O(n^2), 归并排序：O(nlogn)
 *      3. 数据敏感性：快速排序不适用大规模数据集，而归并排序不受数据集限制
 *      4. 空间复杂度：快速排序 O(1)， 归并排序O(n)
 *      5. 效率：快速排序在小规模数据集更有效，归并排序在大规模数据集更有效
 *      6. 排序方法：快速排序是内部排序，在内存中进行，归并排序是外部排序，可使用额外空间
 *      7. 稳定性：快速排序不是一个稳定性排序算法
 *      8. 对数组和链表敏感度：归并排序两者都适合，快速排序更适合数组排序
 *
 *
 *
 */


int partition(int A[], int low, int high){
    int pivot = A[high];
    int i = low-1;
    int j = low;

    while (j<high){
        if (A[j] < pivot){
            int tmp = A[++i];
            A[i] = A[j];
            A[j] = tmp;
        }
        j++;
    }

    int tmp = A[i+1];
    A[i+1] = A[high];
    A[high] = tmp;

    return i+1;
}

void quickSort(int A[], int low, int high){
    if (low < high){
        int pi = partition(A, low, high);

        quickSort(A, low, pi-1);
        quickSort(A, pi+1, high);
    }
}



int main(){
    int A[] = {1, 8, 3, 9, 4, 5, 4, 7};
    quickSort(A, 0, 7);

    for (int i=0; i <8; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}