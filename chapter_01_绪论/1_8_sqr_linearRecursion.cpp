//
// Created by Yang Shuangzhen on 2020/7/1.
//

#include <iostream>
using namespace std;

inline __int64_t sqr(__int64_t a){return a*a;}
__int64_t power2 (int n);


int main(){
    int n = 4;
    cout << "2 的 " << n << "次方为 " << power2(n) << endl;

    return 0;
}

__int64_t power2 (int n){
    if (n == 0)
        return 1;
    if (n & 1)
        return sqr ( power2( n >> 1)) << 1;
    else
        return sqr( power2( n >> 1));
}
