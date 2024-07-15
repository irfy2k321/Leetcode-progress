class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        nodes: Dict[int, TreeNode] = {}
        child_parent = set()
        
        for parent_val, child_val, is_left in descriptions:
            if parent_val not in nodes:
                nodes[parent_val] = TreeNode(parent_val)
            if child_val not in nodes:
                nodes[child_val] = TreeNode(child_val)
                
            parent_node = nodes[parent_val]
            child_node = nodes[child_val]
            
            if is_left:
                parent_node.left = child_node
            else:
                parent_node.right = child_node
            
            child_parent.add(child_val)
        
        # The root node is the one that is not anyone's child
        root_val = next(node for node in nodes if node not in child_parent)
        return nodes[root_val]