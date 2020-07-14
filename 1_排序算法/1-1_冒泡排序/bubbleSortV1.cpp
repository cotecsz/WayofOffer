//
// Created by Yang Shuangzhen on 2020/7/13.
//

#include <iostream>
using namespace std;

/*
 * 1. 无优化版本
 *    依据冒泡排序定义，依次比较相邻两个元素，进行n次，即可得到有序数组。
 *    两个for 循环，外循环 n - 1
 *                内循环 n - i - 1
 */

void bubbleSortV1(int A[], int n){
    for (int i=0; i < n-1; i++){
        for (int j=0; j < n-i-1; j++){
            if (A[j] > A[j+1])
                swap(A[j], A[j+1]);
        }
    }
}

