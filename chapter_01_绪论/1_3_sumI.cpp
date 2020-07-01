//
// Created by Yang Shuangzhen on 2020/7/1.
//

#include <iostream>
using namespace std;

int sumI (int A[], int n);

int main(){
    int A[5] = {1, 2, 3, 4, 5};

    int sum = sumI(A, 5);
    cout << "sum(A[]) = " << sum << endl;

    return 0;
}

int sumI(int A[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += A[i];

    return sum;
}
