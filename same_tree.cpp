#include <iostream>
#include <vector>
#include <queue>

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
            if(!isSameTree(p->left, q->left) || !isSameTree(p->right, q->right)){
                return false;
            }
        }

        return true;
    }
};

TreeNode* createTree(vector<int> in_nodes){

    TreeNode* root, *tmp;
    queue<TreeNode*> nodes;

    root = new TreeNode(in_nodes[0]);
    nodes.push(root);
    
    for(int i = 1; i < in_nodes.size(); i += 2){
        tmp = nodes.front();
        nodes.pop();

        tmp->left = new TreeNode(in_nodes[i]);
        tmp->right = new TreeNode(in_nodes[i+1]);

        nodes.push(tmp->left);
        nodes.push(tmp->right);
    }

    return root;
}

int main(){
    
    TreeNode* test = createTree({1, 2, 3, 4, 5, 6, 7});

    return 0;
}