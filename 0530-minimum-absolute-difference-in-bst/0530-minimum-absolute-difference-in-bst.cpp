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
    int getMinimumDifference(TreeNode* root) {
        int minDifference = 1000000;
        int prevVal = -1;
        return Helper(root, minDifference, prevVal);
    }

    int Helper(TreeNode* node, int& minDifference, int& prevVal) {
        if (!node) {
            return minDifference;
        }
        minDifference = Helper(node->left, minDifference, prevVal);
        if (prevVal != -1) {
            int difference = node->val - prevVal;
            if (difference < minDifference) {
                minDifference = difference;
            }
        }
        prevVal = node->val;
        return Helper(node->right, minDifference, prevVal);
    }
};