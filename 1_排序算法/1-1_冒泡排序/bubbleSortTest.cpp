//
// Created by Yang Shuangzhen on 2020/7/13.
//

#include <iostream>
#include "bubbleSortV1.cpp"
#include "bubbleSortV2.cpp"
#include "bubbleSortV3.cpp"
using namespace std;

int main(){
    int A[8] = {2, 3, 4, 1, 5, 8, 7, 6};
    bubbleSortV3(A, 8);

    for (int i=0; i < 8; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}

