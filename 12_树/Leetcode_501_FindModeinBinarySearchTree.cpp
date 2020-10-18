//
// Created by Yang Shuangzhen on 2020/10/18.
//

#include <vector>
#include <stack>
#include <unordered_map>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
};

/*
 * 对于非二叉搜索树，
 *      1. 遍历整棵树，将值及对应的个数存在map中
 *      2. 将其存放至vector中，对其个数进行排序
 *      3. 取第一个及与第一个相等的元素返回
 *
 */
class SolutionNotBST {
public:
    std::vector<int> findMode(TreeNode* root) {
        std::unordered_map<int, int> map;
        std::vector<int> res;
        if (root == nullptr)    return res;

        traversal(root, map);
        std::vector<std::pair<int, int>> vec(map.begin(), map.end());
        std::sort(vec.begin(), vec.end(), cmp);

        res.push_back(vec[0].first);
        for (int i=1; i<vec.size(); i++){
            if (vec[i].second == vec[0].second){
                res.push_back(vec[i].first);
            }
        }
        return res;
    }

    static bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b){
        return a.second > b.second;
    }

private:
    void traversal(TreeNode* root, std::unordered_map<int, int>& map){
        if (root == nullptr)    return;

        map[root->val]++;
        traversal(root->left, map);
        traversal(root->right, map);
        return ;
    }
};

/*
 * 对于二叉搜索树，中序遍历是有序的，所以使用双指针
 *      1. 递归中序
 *      2. 迭代中序
 */

class SolutionBSTInorder {
public:
    std::vector<int> findMode(TreeNode* root) {
        count = 0;
        maxCount = 0;
        pre = nullptr;
        res.clear();

        searchBST(root);
        return res;
    }
private:
    TreeNode* pre;
    int count;
    int maxCount;
    std::vector<int> res;

    void searchBST(TreeNode* cur){
        if (cur == nullptr)     return;

        searchBST(cur->left);               // 左
        // cur->val 与 pre->val 确定count
        if (pre == nullptr){
            count = 1;
        }
        else if (pre->val == cur->val){
            count++;
        }
        else{
            count = 1;
        }
        pre = cur;

        // count 与 maxCount 确定 res
        if (count == maxCount){
            res.push_back(cur->val);
        }
        if (count > maxCount){
            res.clear();
            maxCount = count;
            res.push_back(cur->val);
        }

        searchBST(cur->right);              // 右
        return ;
    }
};

class SolutionBSTInorderIteration {
public:
    std::vector<int> findMode(TreeNode* root) {
        std::vector<int> res;
        res.clear();
        if (root == nullptr)    return res;

        int count = 0;
        int maxCount = 0;
        std::stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        while (cur != nullptr || !st.empty()){
            if (cur != nullptr){
                st.push(cur);
                cur = cur->left;                // 左
            }
            else{
                cur = st.top();                 // 中
                st.pop();

                if (pre == nullptr){
                    count = 1;
                }
                else if (pre->val == cur->val){
                    count++;
                }
                else {
                    count = 1;
                }

                if (count == maxCount){
                    res.push_back(cur->val);
                }
                if (count > maxCount){
                    res.clear();
                    maxCount = count;
                    res.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;               // 右
            }
        }

        return res;
    }
};

/*
 *                    a 3
 *                 /       \
 *               b 1       c 5
 *             /    \      /   \
 *           d 0    e 2   f 3  g 6
 */
int main(){
    TreeNode a(3);
    TreeNode b(1);
    TreeNode c(5);
    TreeNode d(0);
    TreeNode e(2);
    TreeNode f(3);
    TreeNode g(6);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;

    std::vector<int> res{3};
    SolutionNotBST solNotBST;
    assert(solNotBST.findMode(&a) == res);

    SolutionBSTInorder solBST;
    assert(solBST.findMode(&a) == res);

    SolutionBSTInorderIteration solBSTIterInord;
    assert(solBSTIterInord.findMode(&a) == res);

    return 0;
}