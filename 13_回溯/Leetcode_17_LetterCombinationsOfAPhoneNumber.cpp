//
// Created by Yang Shuangzhen on 2020/10/30.
//

#include <string>
#include <vector>

/*
 * Leetcode 17 电话号码的字母组合
 *     基本思路：回溯。
 *        1. 终止条件：大小与给定数字个数相等即保存
 *        2. 找出数字对应的字符，遍历回溯
 */
class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        s.clear();
        res.clear();
        if (digits.size() == 0){
            return res;
        }

        backtracing(digits, 0);
        return res;
    }

    void backtracing(std::string& digits, int index){
        if (index == digits.size()){
            res.push_back(s);
            return ;
        }

        int digit = digits[index] - '0';
        std::string letter = letterMap[digit];      // 取得数字对应的字符
        for (int i=0; i<letter.size(); i++){
            s.push_back(letter[i]);
            backtracing(digits, index+1);
            s.pop_back();
        }
    }

private:
    std::string s;
    std::vector<std::string> res;
    std::vector<std::string> letterMap = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    };
};

int main(){
    std::string digits("23");
    std::vector<std::string> res {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};

    Solution sol;
    assert(sol.letterCombinations(digits) == res);

    return 0;
}