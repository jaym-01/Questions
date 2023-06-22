#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        else if(p == NULL || q == NULL){
            return false;
        }
        else if(p->val != q->val){
            return false;
        }
        else{
            if(!isSameTree(p->left, q->left) || !isSameTree(p->left, q->right)){
                return false;
            }
        }

        return true;
    }
};

TreeNode* createTree(){
    return new TreeNode(1, new TreeNode(2, NULL, NULL), new TreeNode(3, NULL, NULL));
}

int main(){
    Solution s1;

    cout << s1.isSameTree(createTree(), createTree()) << endl;
}