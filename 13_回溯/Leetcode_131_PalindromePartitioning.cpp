//
// Created by Yang Shuangzhen on 2020/11/4.
//

#include <vector>
#include <string>

/*
 * Leetcode131 分割回文串
 *     基本思路：将字符串的分割问题抽象为选择
 *             将字符串从i处分割，当[startIndex, i] 为回文字符串保存，
 *             回溯 startIndex=i+1,判断后面子串是否为回文字符串
 *             当 startIndex > s.size() 时，表示该串被分割为回文字符串
 */
class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        path.clear();
        res.clear();
        backtracing(s, 0);
        return res;
    }

private:
    std::vector<std::string> path;
    std::vector<std::vector<std::string>> res;

    void backtracing(std::string& s, int startIndex){
        if (startIndex >= s.size()){
            res.push_back(path);
            return ;
        }

        for (int i=startIndex; i<s.size(); i++){
            // 判断 [startIndex, i] 是否为回文字符串
            if (isPalindrome(s, startIndex, i)){
                std::string str = s.substr(startIndex, i-startIndex+1);
                path.push_back(str);
            }else{
                continue;
            }
            backtracing(s, i+1);
            path.pop_back();
        }
    }

    bool isPalindrome(const std::string& s, int start, int end){
        for (int i=start, j=end; i < j; i++, j--){
            if (s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    std::string s("aab");
    std::vector<std::vector<std::string>> res{{"a", "a", "b"},
                                              {"aa", "b"},
                                              };


    Solution sol;
    assert(sol.partition(s) == res);
    return 0;
}