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
    long last;
    bool inorder(TreeNode* root){
        if (!root) return true;
        if (!inorder(root->left)) return false;
        if (root->val <= last) return false;
        last = root->val;
        return inorder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        last = LONG_MIN;
        return inorder(root);
    }
};
