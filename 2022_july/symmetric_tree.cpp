#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> nodes;
        TreeNode* tmp;

        nodes.push(root->left);
        nodes.push(root->right);

        while(!nodes.empty()){
            tmp = nodes.front();

            nodes.pop();

            if(!check_subtree(tmp, nodes.front(), nodes)){
                return false;
            };
            nodes.pop();
        }

        return true;
    }

private:
    bool check_subtree(TreeNode* left, TreeNode* right, queue<TreeNode*>& nodes){
        if(left == NULL || right == NULL){
            if(left == NULL && right == NULL){
                return true;
            }
            return false;
        }

        nodes.push(left->left);
        nodes.push(right->right);
        nodes.push(left->right);
        nodes.push(right->left);

        bool out = false;

        if (left->val == right->val){
            if(left->left == NULL || right->right == NULL){
                if(!(left->left == NULL && right->right == NULL)){
                    return false;
                }
            }
            else if(!(left->left->val == right->right->val)){
                return false;
            }
            
            if(left->right == NULL || right->left == NULL){

                if(!(left->right == NULL && right->left == NULL)){
                    return false;
                }

            }
            else if(!(left->right->val == right->left->val)){
                return false;
            }
        }
        else{
            return false;
        }

        return true;
    }
};

TreeNode* createTree(vector<int> in){
    TreeNode* out = new TreeNode(in[0]);

    TreeNode* root;

    queue<TreeNode*> next;
    next.push(out);

    for(int i = 1; i < in.size(); i+=2){
        root = next.front();
        next.pop();

        if(in[i] == NULL){
            root->left = NULL;
        }
        else{
            root->left = new TreeNode(in[i]);
            next.push(root->left);
        }

        if(in[i+1] == NULL){
            root->right = NULL;
        }
        else{
            root->right = new TreeNode(in[i+1]);
            next.push(root->right);
        }
    }

    return out;
}

void deallocate(TreeNode* root){
    if(root == NULL){
        return;
    }
    else{
        deallocate(root->left);
        deallocate(root->right);

        delete root;
    }
}

int main()
{
    Solution s1;

    vector<int> in1 {1,2,2,NULL,3,NULL,3};

    TreeNode *t1 = createTree(in1);

    cout << s1.isSymmetric(t1) << endl;

    deallocate(t1);
}
