//
// Created by Yang Shuangzhen on 2020/7/1.
//

#include <iostream>
using namespace std;

int countOnes(unsigned int n);

int main(){
    int n = 8;

    int ones = countOnes(n);
    cout << n << " 二进制展开中数位为 1 的个数为：" << ones << endl;

    return 0;
}

int countOnes(unsigned int n){
    int ones = 0;

    while ( n > 0){
        ones += (1 & n);
        n >>= 1;
    }

    return ones;
}
