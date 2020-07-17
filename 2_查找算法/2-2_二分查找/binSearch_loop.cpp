//
// Created by Yang Shuangzhen on 2020/7/14.
//

#include <iostream>
using namespace std;

/*
 * 二分查找版本1：
 *    比较查找元素小于中间元素，则进行折半，hi = mid
 *    如果查找元素等于中间元素，则返回 mid
 *    如果查找元素大于中间元素，则进行折半，lo = mid+1
 *
 */

int binSearchLoop(int A[], int elem, int lo, int hi){

    while (lo < hi){
        int mid = lo + (hi - lo) / 2;
        if (elem < A[mid])  hi = mid;
        else if (elem == A[mid]) return mid;
        else    lo=mid+1;
    }

    return -1;
}

