//
// Created by Yang Shuangzhen on 2020/9/8.
//

#include <string>

/*
 * 基本思路：
 *      原地修改 + 双指针
 *      先遍历一次，搜索出空格的个数，然后将字符串大小resize为 s.size()+count*2,
 *      再使用双指针从后往前遍历，将空格替换为20%
 *      
 */
class Solution {
public:
    std::string replaceSpace(std::string s) {
        int count = 0;
        for (int i=0; i<s.size(); i++){
            if (s[i] == ' '){
                count++;
            }
        }

        int oldSize = s.size();
        s.resize(s.size() + count*2);
        int newSize = s.size();
        for (int i=oldSize-1, j=newSize-1; i >= 0; i--, j--){
            if (s[i] != ' '){
                s[j] = s[i];
            }
            else{
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 2;
            }
        }

        return  s;
    }
};


int main(){
    std::string s = "we are family";

    Solution sol;
    assert(sol.replaceSpace(s) == "we%20are%20family");

    return 0;
}


