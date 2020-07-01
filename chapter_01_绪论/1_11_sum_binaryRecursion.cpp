//
// Created by Yang Shuangzhen on 2020/7/1.
//

#include <iostream>
using namespace std;

int sum(int A[], int lo, int hi);

int main(){
    int A[5] = {1, 2, 3, 4, 5};

    int res = sum(A, 0, 4);
    cout << "sum(A[]) = " << res << endl;

    return 0;
}

int sum(int A[], int lo, int hi){
    if (lo == hi)
        return A[lo];
    else{
        int mi = (lo + hi) >> 1;
        return sum(A, lo, mi) + sum(A, mi+1, hi);
    }
}
