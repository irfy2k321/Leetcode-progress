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
    int minDiffInBST(TreeNode* root) {
        int minDiff = 1000000;
        int prevVal = -1;
        inorderTraversal(root, minDiff, prevVal);
        return minDiff;
    }

    void inorderTraversal(TreeNode* node, int& minDiff, int& pVal)
    {
        if (!node) return;
        inorderTraversal(node->left, minDiff, pVal);
        if (pVal != -1)
        {
            int dif = node->val -pVal;
            if (dif < minDiff)
            minDiff = dif;
        }

        pVal = node->val;

        inorderTraversal(node->right, minDiff, pVal);
    }
};