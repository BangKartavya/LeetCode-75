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
    int maxi = 0;
    // 0 -> left 1 -> right
    void solve(TreeNode* root, int dir, int currLen) {
        if(!root) return;
        maxi = max(maxi,currLen);

        solve(root->left,0, dir==0? 1: currLen+1);
        solve(root->right,1, dir==1? 1: currLen+1);
    }
public:
    int longestZigZag(TreeNode* root) {
        solve(root,0,0);
        solve(root,1,0);

        return maxi;
    }
};