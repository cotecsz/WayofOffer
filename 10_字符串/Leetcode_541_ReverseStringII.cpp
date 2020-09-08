//
// Created by Yang Shuangzhen on 2020/9/8.
//

#include <string>
#include <iostream>

/*
 * Leetcode 541:反转字符串II
 *      每隔2K个字符反转前k个字符，如果小于k个字符，则全部反转。
 *      基本思路：
 *          一次遍历，i += k*2
 *
 */

class Solution {
public:

    void reverse(std::string& s, int start, int end){
        int offset = (end - start + 1) / 2;         // end-start+1
        for (int i=start, j=end; i < start+offset; i++, j--){
            std::swap(s[i], s[j]);
        }
    }

    std::string reverseStr(std::string s, int k) {
        for (int i=0; i < s.size(); i+=(k*2)){      // i+= (k*2)
            if (i + k <= s.size()){
                reverse(s, i, i+k-1);       // i+k-1
                continue;
            }
            reverse(s, i, s.size()-1);      // s.size()-1
        }

        return s;
    }
};


int main(){
    std::string s = "abcdefg";

    Solution sol;
    assert(sol.reverseStr(s, 2) == "bacdfeg");

    return 0;
}
