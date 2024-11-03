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
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> modes;
        int maxCount = 0, currentCount = 0;
        TreeNode* prev = nullptr;

        inorderTraversal(root, prev, currentCount, maxCount, modes);
        return modes;
    }
    void inorderTraversal(TreeNode* node, TreeNode*& prev, int& currentCount, int& maxCount, vector<int>& modes) 
    {
        if (!node) return;
        inorderTraversal(node->left, prev, currentCount, maxCount, modes);
        handleValue(node->val, prev, currentCount, maxCount, modes);
        inorderTraversal(node->right, prev, currentCount, maxCount, modes);
    }
    void handleValue(int val, TreeNode*& prev, int& currentCount, int& maxCount, vector<int>& modes) 
    {
        if (prev == nullptr || val != prev->val) 
        {
            currentCount = 1;
        } 
        else 
        {
            currentCount++;
        }
        if (currentCount > maxCount) 
        {
            maxCount = currentCount;
            modes = {val};
        } 
        else if (currentCount == maxCount) 
        {
            modes.push_back(val);
        }
        prev = new TreeNode(val);
    }
};