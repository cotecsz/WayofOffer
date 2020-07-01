//
// Created by Yang Shuangzhen on 2020/7/1.
//

using namespace std;

void reverse(int* A, int lo, int hi){
    if (lo < hi){
        swap (A[lo], A[hi]);
        reverse(A, lo+1, hi-1);
    }
}