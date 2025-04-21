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
    public:
        vector<int> rightSideView(TreeNode* root) {
            if(!root) return {};

            vector<int> result;
            queue<TreeNode*> q;
            q.push(root);
            int level = 0;

            while(!q.empty()) {
                int siz = q.size();
                if(siz > 0) result.push_back(q.front()->val);
                while(siz--) {
                    TreeNode* curr = q.front();
                    q.pop();

                    result.back() = curr->val;

                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                level++;
            }

            return result;
        }
};