//
// Created by Yang Shuangzhen on 2020/7/22.
//

/*
 *  Leetcode 402 移除K个数字
 *      已知一个使用字符串的非负整数，求移除K个数字后，获得最小的可能新数字
 *
 *      从高位向低位遍历，如果对应数字大于下一位数字，将该数字去掉
 *
 *      注意：
 *      1. 所有数字扫描完成 k 仍大于0，比如 12345 k =3   依次出栈
 *      2. 当数字有0 比如 100200, k=1
 *      3. 返回字符串
 *
 */
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int> S;
        string res{};

        for (int i=0; i < num.length(); i++){
            int number = num[i] - '0';

            // 新数字 > 栈中数字，弹出
            while (S.size() != 0 && S[S.size()-1] > number && k > 0){
                S.pop_back();
                k--;
            }
            // 入栈
            if (number != 0 || S.size() != 0){
                S.push_back(number);
            }
        }

        while (S.size() != 0 && k > 0){
            S.pop_back();
            k--;
        }

        for (int i=0; i < S.size(); i++){
            res.append(1, '0'+S[i]);
        }

        if (res == ""){
            res = "0";
        }

        return res;
    }
};


int main(){
    string num{"10002000"};
    int k = 3;

    Solution sol;
    string res = sol.removeKdigits(num, k);

    std::cout << res << std::endl;
//    assert(res == "12");

    return 0;
}
