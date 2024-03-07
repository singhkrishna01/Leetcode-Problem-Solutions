# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        maxDepth = 0
        lca = root

        def dfs(curNode, depth):
            nonlocal maxDepth
            nonlocal lca
            if not curNode:
                return depth-1

            leftDepth = dfs(curNode.left, depth+1)
            rightDepth = dfs(curNode.right, depth+1)

            if leftDepth > maxDepth or rightDepth > maxDepth:
                lca = curNode
            elif leftDepth == rightDepth == maxDepth:
                lca = curNode
            
            maxDepth = max(leftDepth, rightDepth, maxDepth)

            return max(leftDepth, rightDepth)

        dfs(root, 0)
        return lca
    