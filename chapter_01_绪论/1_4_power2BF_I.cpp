//
// Created by Yang Shuangzhen on 2020/7/1.
//

#include <iostream>
using namespace std;

__int64_t power2BF_I(int n);

int main(){
    int n = 4;
    cout << "2 的 " << n << "次方为 " << power2BF_I(n) << endl;

    return 0;
}

__int64_t power2BF_I(int n){
    __int64_t pow = 1;
    while( 0 < n--)
        pow <<= 1;

    return pow;
}