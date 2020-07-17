//
// Created by Yang Shuangzhen on 2020/7/14.
//

#include <iostream>
using namespace std;

int find(int A[], int n, int num){
    for (int i=0; i < n; i++){
        if (A[i] == num)
            return i;
    }
}

int main(){
    int A[8] = {2, 5, 8, 9, 10, 3, 1, 7};

    int idx = find(A, 8, 1);
    assert( idx==6 );
    cout << "1 pos is " << idx << endl;

    return 0;
}
