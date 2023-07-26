#include <iostream>

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
    void flatten(TreeNode* root) {
        getNextNode(root);
    }

    //returns final node of the subtree
    TreeNode* getNextNode(TreeNode *parent){
        if(parent == NULL){
            return NULL;
        }
        else if(parent->left == NULL && parent->right == NULL){
            return parent;
        }

        TreeNode* finalLeft = getNextNode(parent->left);

        TreeNode* finalRight = getNextNode(parent->right);

        if(finalLeft == NULL){
            return finalRight;
        }
        else{
            finalLeft->right = parent->right;
            parent->right = parent->left;
            parent->left = NULL;

            if(finalRight == NULL){
                return finalLeft;
            }
            else{
                return finalRight;
            }
        }
    }
};
