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
    bool helper(TreeNode* left, TreeNode* right){
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        // A tree is symmetric is equivalent to the left subtree of its rootis a mirror reflection to the right subtree of its root. It will be easy to judge mirror reflection with a helper function with recursion. 
        if (!root) return false;
        return helper(root->left, root->right);
    }
};
