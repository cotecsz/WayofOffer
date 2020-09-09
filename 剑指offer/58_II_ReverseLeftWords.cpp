//
// Created by Yang Shuangzhen on 2020/9/9.
//

#include <string>

class Solution {
public:
    std::string reverseLeftWords(std::string s, int n) {
//        std::reverse(s.begin(), s.begin()+n);
//        std::reverse(s.begin()+n, s.end());
//        std::reverse(s.begin(), s.end());

        reverse(s, 0, n-1);
        reverse(s, n, s.size()-1);
        reverse(s, 0, s.size()-1);

        return s;
    }

    void reverse(std::string& s, int start, int end){
        for (int i=start, j=end; i < j; i++, j--){
            std::swap(s[i], s[j]);
        }
    }
};


int main(){
    std::string s("abhello");

    Solution sol;
    assert(sol.reverseLeftWords(s, 2) == "helloab");

    return 0;
}




