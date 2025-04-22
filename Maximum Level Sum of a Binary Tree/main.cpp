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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return 0;
        q.push(root);
        int level = 1;

        int result = INT_MIN;
        int maxLevel = 0;

        while(!q.empty()) {
            int siz = q.size();
            int sum = 0;

            while(siz--) {
                TreeNode* curr = q.front();
                q.pop();

                sum += curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            if(sum > result) {
                result = sum;
                maxLevel = level;
            }
            level++;
        }

        return maxLevel;
    }
};