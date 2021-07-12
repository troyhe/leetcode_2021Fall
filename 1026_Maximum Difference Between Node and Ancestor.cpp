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
    int maxDiff;
    vector<int> helper(TreeNode* root){
        int val = root->val;
        vector<int> ans(2, val);
        if (root->left){
            vector<int> left = helper(root->left);
            maxDiff = max(maxDiff, abs(val - left[0]));
            maxDiff = max(maxDiff, abs(val - left[1]));
            ans[0] = min(ans[0], left[0]);
            ans[1] = max(ans[1], left[1]);
        }
        if (root->right){
            vector<int> right = helper(root->right);
            maxDiff = max(maxDiff, abs(val - right[0]));
            maxDiff = max(maxDiff, abs(val - right[1]));
            ans[0] = min(ans[0], right[0]);
            ans[1] = max(ans[1], right[1]);
        }
        return ans;
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        maxDiff = 0;
        if (root) helper(root);
        return maxDiff;
    }
};
