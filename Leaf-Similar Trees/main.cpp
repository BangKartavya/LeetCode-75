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
    void leaves(TreeNode* root, vector<int>& res) {
        if(!root) return;

        if(!root->left && !root->right) {
            res.push_back(root->val);
            return;
        }
        leaves(root->left,res);
        leaves(root->right,res);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        vector<int> res2;

        leaves(root1,res1);
        leaves(root2,res2);

        if(res1.size() != res2.size()) return false;

        int n = res1.size();

        for(int i = 0;i<n;i++) if(res1[i] != res2[i]) return false;

        return true;

    }
};