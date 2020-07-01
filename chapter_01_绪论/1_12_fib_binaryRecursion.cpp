//
// Created by Yang Shuangzhen on 2020/7/1.
//
#include <iostream>
using namespace std;

__int64_t fib(int n);

int main(){
    int n = 5;
    __int64_t res = fib(n);

    cout << "fib(" << n << ") = " << res << endl;

    return 0;
}

__int64_t fib(int n){
    if (n < 2)
        return (__int64_t) n;
    else
        return fib(n-1) + fib(n-2);
}
