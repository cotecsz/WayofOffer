//
// Created by Yang Shuangzhen on 2020/8/6.
//

#include <iostream>

using std::cout;
using std::endl;


/*
 * 归并排序：
 *      1. 分解问题：将数组[1, A] 分解为 A[1, n/2] 和 [n/2 +1, n] 排序问题
 *      2. 递归求解：递归解决子问题得到两个有序子数组
 *      3. 合并排序：将两个有序数组合并为一个有序数组
 *
 * 复杂度分析：
 *      时间复杂度：
 *          T(n) = 2T(n/2) + O(n)  T(1) = 1
 *          主定理得：O(nlogn)
 *      空间复杂度：
 *          2 4 8 ...
 *          O(n)
 *      结论：
 *          1. 归并排序非原地排序，是以空间换时间的排序算法。
 *          2. 归并排序是稳定的排序算法，在合并时值相同的两个关键字不存在交换的可能。
 *
 * 分而治之策略：
 *      1. 分解原问题
 *      2. 解决子问题
 *      3. 合并问题解
 */

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 将需要合并的两个子数组保存至临时变量中
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i=0; i < n1; i++)
        L[i] = arr[left+i];
    for (int j=0; j < n2; j++)
        R[j] = arr[mid+1+j];

    // 合并临时数组，将结果保存至 arr[left-Right]
    int i=0, j=0, k=left;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    // L有剩余时，依次存放至有序数组后
    while (i < n1){
        arr[k++] = L[i++];
    }
    // R有剩余时，依次存放至有序数组后
    while (j < n2){
        arr[k++] = R[j++];
    }

}

void mergeSort(int arr[], int left, int right){
    if (left < right) {
        // 分解问题
        int mid = (left + right) / 2;

        // 递归求解
        cout << "mergeSort(" << left << ", " << mid << ")" << endl;
        mergeSort(arr, left, mid);
        cout << "mergeSort(" << mid+1 << ", " << right << ")" << endl;
        mergeSort(arr, mid+1, right);


        // 合并排序
        merge(arr, left, mid, right);
    }
}




int main(){
    int arr[6] = {5, 1, 4, 2, 8, 4};
    mergeSort(arr, 0, 5);

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    return 0;
}



