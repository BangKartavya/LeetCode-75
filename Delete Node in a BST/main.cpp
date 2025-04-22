/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void findSuccessor(TreeNode* root, int val,TreeNode*& suc) {
        if(!root) return;

        if(root->val > val) {
            suc = root;
            findSuccessor(root->left,val,suc);
        }
        else findSuccessor(root->right,val,suc);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(key > root->val) {
            root->right = deleteNode(root->right,key);
        }
        else if(key < root->val) {
            root->left = deleteNode(root->left,key);
        }
        else {
            if(!root->right) {
                TreeNode* temp = root->left;
                delete root;

                return temp;
            }
            if(!root->left) {
                TreeNode* temp = root->right;
                delete root;

                return temp;
            }

            TreeNode* suc = nullptr;

            findSuccessor(root,key,suc);

            root->val = suc->val;
            root->right = deleteNode(root->right,suc->val);
        }

        return root;
    }
};