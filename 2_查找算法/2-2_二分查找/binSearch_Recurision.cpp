//
// Created by Yang Shuangzhen on 2020/7/14.
//

int binSearchRecursion(int A[], int elem, int lo, int hi){
    int mid = lo + (hi - lo) / 2;

    if (lo < hi){
        if (elem < A[mid])
            return binSearchRecursion(A, elem, lo, mid);
        else if (elem == A[mid])
            return mid;
        else
            return binSearchRecursion(A, elem, mid+1, hi);
    }

    return -1;
}