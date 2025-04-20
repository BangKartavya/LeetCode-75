# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def prefix(self,root,curr,target):
        if(not root): return 0
        
        curr += root.val
        cnt = self.mp.get(curr-target,0)
        if(not self.mp.get(curr,0)): self.mp[curr] = 0
        self.mp[curr]+=1
        cnt += self.prefix(root.left,curr,target)
        cnt += self.prefix(root.right,curr,target)
        self.mp[curr]-=1

        return cnt

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.mp = {0:1}

        return self.prefix(root,0,targetSum)