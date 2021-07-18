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
    int num;
    void helper(TreeNode* root, long maxVal){
        if (!root) return;
        if (root->val >= maxVal) num++;
        maxVal = max(maxVal, (long) root->val);
        helper(root->left, maxVal);
        helper(root->right, maxVal);
    }
public:
    int goodNodes(TreeNode* root) {
        num = 0;
        helper(root, LONG_MIN);
        return num;
    }
};
