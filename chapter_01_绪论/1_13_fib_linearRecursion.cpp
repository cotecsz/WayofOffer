//
// Created by Yang Shuangzhen on 2020/7/1.
//

#include <iostream>
using namespace std;

__int64_t fib(int n, __int64_t& prev);

int main(){
    int n = 5;
    __int64_t prev = 0;
    __int64_t res = fib(n, prev);

    cout << "fib(" << n << ") = " << res << endl;

    return 0;
}

__int64_t fib(int n, __int64_t& prev){
    if (n == 0){
        prev = 1;
        return 0;
    }
    else{
        __int64_t prevPrev;
        prev = fib(n -1, prevPrev);
        return prevPrev + prev;
    }
}