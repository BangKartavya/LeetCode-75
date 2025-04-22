# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSuccessor(self,root,val):
        if(not root): return

        if(val < root.val):
            self.suc = root
            self.findSuccessor(root.left,val)
        else:
            self.findSuccessor(root.right,val)

    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if(not root): return None

        if(key < root.val):
            root.left = self.deleteNode(root.left,key)
        elif(key > root.val):
            root.right = self.deleteNode(root.right,key)
        else:
            if(not root.left):
                temp = root.right
                del root
                return temp
            elif(not root.right):
                temp = root.left
                del root
                return temp
            
            self.suc = None
            self.findSuccessor(root,key)
            root.val = self.suc.val
            root.right = self.deleteNode(root.right,self.suc.val)

        return root
