//
// Created by Yang Shuangzhen on 2020/7/1.
//

#include <iostream>
using namespace std;

void bubblesort1A(int A[], int n);

int main(){
    int A[6] = {3, 4, 7, 2, 1, 5};
    bubblesort1A(A, 6);

    for (int i=0; i < 6; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}

void bubblesort1A(int A[], int n){
    bool sorted = false;
    while ( !sorted){
        sorted = true;
        for (int i = 1; i < n; i++){        // 自左向右进行排序，[0, n)无序，[n, 6)右边有序
            if ( A[i-1] > A[i] ){           // A[i-1] 与 A[i] 逆序，交换位置
                swap(A[i], A[i-1]);
                sorted = false;
            }
        }
        n--;
    }
}