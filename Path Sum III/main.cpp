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
    unordered_map<long long,int> mp;
    int prefix(TreeNode* root, long long curr, int target) {
        if(!root) return 0;

        curr += root->val;

        int cnt = mp[curr-target];
        mp[curr]++;
        cnt += prefix(root->left,curr,target);
        cnt += prefix(root->right,curr,target);
        mp[curr]--;

        return cnt;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        return prefix(root,0,targetSum);
    }
};