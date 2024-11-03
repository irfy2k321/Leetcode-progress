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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int TotalSum = 0;
        inOrderTraversal(root, TotalSum, low, high);
        return TotalSum;
    }

    void inOrderTraversal(TreeNode* node, int& TotalSum, int& low, int& high)
    {
        if(!node)
        {
            return;
        }
        inOrderTraversal(node->left, TotalSum, low, high);
        if(node->val >= low && node->val <= high)
        {
            TotalSum += node->val;
        }
        inOrderTraversal(node->right, TotalSum, low, high);
    }
};