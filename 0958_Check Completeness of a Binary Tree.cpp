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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        int end = false;
        queue<TreeNode*> level; 
        level.push(root);
        while (!level.empty()){
            TreeNode* cur = level.front();
            level.pop();
            if (!end){
                if (cur->left) level.push(cur->left);
                else end = true;
            } else {
                if (cur->left) return false;
            }
            if (!end){
                if (cur->right) level.push(cur->right);
                else end = true;
            } else {
                if (cur->right) return false;
            }
        }
        return true;
    }
};
