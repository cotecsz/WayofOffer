//
// Created by Yang Shuangzhen on 2020/7/1.
//

#include <iostream>
using namespace std;

int sum(int A[], int n);

int main(){
    int A[5] = {1, 2, 3, 4, 5};

    int res = sum(A, 5);
    cout << "sum(A[]) = " << res << endl;

    return 0;
}

int sum(int A[], int n){
    if (n < 1)
        return 0;
    else
        return sum(A, n-1) + A[n-1];
}