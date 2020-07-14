//
// Created by Yang Shuangzhen on 2020/7/13.
//

#include <iostream>
using namespace std;


/*
 * 3. 二次优化
 *    添加两个指针用于记录最后一次交换的位置和 有序与无序的边界。
 *    外循环进行 n - 1次
 *    内循环 进行 无序数组的排序
 *
 *    最坏时间复杂度：O(n^2)
 *    最好时间复杂度：O(n)
 */
void bubbleSortV3(int A[], int n){
    bool sorted;                // 记录数组是否有序
    int lastSwappedIndex = 0;   // 记录最后一次交换的位置
    int sortBoard = n - 1;      // 记录有序和无序的边界

    for (int i=0; i < n-1; i++){
        sorted = true;

        // 将无序部分进行排序
        for (int j = 0; j < sortBoard; j++){
            if (A[j] > A[j+1]){
                swap(A[j], A[j+1]);
                sorted = false;
                lastSwappedIndex = j;
            }
        }
        sortBoard = lastSwappedIndex;

        if (sorted)
            break;
    }
}

