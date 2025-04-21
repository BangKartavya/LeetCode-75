# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # 0 -> to go left 1 -> to go right

    def solve(self,root,d,currLen):
        if(not root): return 0
        self.maxi = max(self.maxi,currLen)

        if(d == 0):
            self.solve(root.left,0,1)
            self.solve(root.right,1,currLen+1)
        else:
            self.solve(root.left,0,currLen+1)
            self.solve(root.right,1,1)
        
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.maxi = 0
        self.solve(root,0,0)
        self.solve(root,1,0)

        return self.maxi