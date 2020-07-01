//
// Created by Yang Shuangzhen on 2020/7/1.
//

using namespace std;

void reverse(int* A, int lo, int hi){
    while ( lo < hi)
        swap(A[lo++], A[hi--]);
}