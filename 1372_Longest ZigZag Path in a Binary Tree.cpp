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
    int maxLength;
    int longestZigZagHelper(TreeNode* root, bool isleft){
        // If the boolean value isleft is true, the root should be a left child of its father. 
        if (!root) return 0; 
        int left = longestZigZagHelper(root->left, true);
        int right = longestZigZagHelper(root->right, false);
        int longer = max(left, right);
        maxLength = max(maxLength, longer);
        if (isleft) return right + 1;
        else return left + 1;
    }

public:
    int longestZigZag(TreeNode* root) {
        maxLength = 0;
        longestZigZagHelper(root, true);
        longestZigZagHelper(root, false);
        return maxLength;   
    }
};
