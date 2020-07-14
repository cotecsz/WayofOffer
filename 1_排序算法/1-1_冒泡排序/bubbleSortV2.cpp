//
// Created by Yang Shuangzhen on 2020/7/13.
//

#include <iostream>
using namespace std;

/*
 * 2. 一次优化版本
 *    对于有序数组，一次遍历即可完成。时间复杂度：O(n)
 */
void bubbleSortV2(int A[], int n){
    bool sorted = false;
    while (!sorted){
        sorted = true;
        for (int i=0; i<n-1; ++i){
            if (A[i] > A[i+1]){
                swap(A[i], A[i+1]);
                sorted = false;
            }
        }
    }
}
