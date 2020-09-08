//
// Created by Yang Shuangzhen on 2020/9/8.
//

#include <vector>


class Solution {
public:
    void reverseString(std::vector<char> &s) {
        for (int i=0, j=s.size()-1; i < j; i++, j--){
            std::swap(s[i], s[j]);
        }
    }
};

int main(){
    std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    std::vector<char> rs = {'o', 'l', 'l', 'e', 'h'};

    Solution sol;
    sol.reverseString(s);
    assert(s == rs);

    return 0;
}

