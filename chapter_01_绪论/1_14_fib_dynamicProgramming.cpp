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

__int64_t fibI(int n){
    __int64_t f =1 g = 0;
    while (0 < n--){
        g += f;
        f = g-f;
    }
    return g;
}
