//
// Created by Yang Shuangzhen on 2020/7/14.
//


#include "binSearch_loop.cpp"
#include "binSearch_Recurision.cpp"

using namespace std;

int main(){
    int A[8] = {0, 1, 2, 3, 4, 5, 6, 7};

    int n = 8;
    int elem = 0;
//    int idx = binSearchLoop(A, elem, 0, n);
    int idx = binSearchRecursion(A, elem, 0, n);

    cout << elem << " position is " << idx << endl;

    return 0;
}
