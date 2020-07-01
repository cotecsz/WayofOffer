//
// Created by Yang Shuangzhen on 2020/7/1.
//

#include <iostream>
//#include "1_7_reverse.cpp"
#include "1_10_reverse.cpp"

using namespace std;

void reverse(int*, int, int);
void reverse(int* A, int n);

int main(){
    int A[5] = {1, 2, 3, 4, 5};

    reverse(A, 5);
    for (int i=0; i < 5; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}

void reverse(int* A, int n){
    reverse(A, 0, n-1);
}


