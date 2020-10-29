//
// Created by Yang Shuangzhen on 2020/10/27.
//

#include <vector>

/*
 * 暴力破解：遍历数组，使用双指针，若前一个数大于后一个指针指向的数，则找到该旋转数。
 */
class Solution {
public:
    int minArray(std::vector<int>& numbers) {
        int i = 0;
        for (int j=1; j<numbers.size(); j++){
            if (numbers[i] > numbers[j]){
                return numbers[j];
            }
        }
        return numbers[i];
    }
};

int main(){
    std::vector<int> numbers({3, 4, 5, 1, 2});

    Solution sol;
    assert(sol.minArray(numbers) == 1);

    return 0;
}
