# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def getDirections(self, root: Optional[TreeNode], startValue: int, destValue: int) -> str:
        # Helper function to find the path from the root to the given value
        def findPath(root, value, path):
            if not root:
                return False
            if root.val == value:
                return True
            path.append('L')
            if findPath(root.left, value, path):
                return True
            path.pop()
            path.append('R')
            if findPath(root.right, value, path):
                return True
            path.pop()
            return False

        # Helper function to find the LCA of two values
        def findLCA(root, p, q):
            if not root or root.val == p or root.val == q:
                return root
            left = findLCA(root.left, p, q)
            right = findLCA(root.right, p, q)
            if left and right:
                return root
            return left if left else right

        # Find the path from root to startValue
        path_to_start = []
        findPath(root, startValue, path_to_start)

        # Find the path from root to destValue
        path_to_dest = []
        findPath(root, destValue, path_to_dest)

        # Find the LCA of startValue and destValue
        lca = findLCA(root, startValue, destValue)
        path_to_lca = []
        findPath(root, lca.val, path_to_lca)

        # Directions to LCA
        directions_to_lca = 'U' * (len(path_to_start) - len(path_to_lca))
        # Directions from LCA to destination
        directions_from_lca_to_dest = ''.join(path_to_dest[len(path_to_lca):])

        return directions_to_lca + directions_from_lca_to_dest

        