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
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inOrderTraversal(root, nodes);
        TreeNode* newRoot = new TreeNode(0);
        TreeNode* current = newRoot;

        for(TreeNode* node : nodes)
        {
            current->right = node;
            current = current->right;
            current->left = nullptr;
        }   

        return newRoot->right;
    }

    void inOrderTraversal(TreeNode* node, vector<TreeNode*>& nodes)
    {
        if(!node)
        {
            return;
        }
        inOrderTraversal(node->left, nodes);
        nodes.push_back(node);
        inOrderTraversal(node->right, nodes);
    }
};