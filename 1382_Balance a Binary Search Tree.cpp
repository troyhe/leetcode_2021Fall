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
    void inorderTraversal(TreeNode* root, vector<int>& ans){
        if (!root) return;
        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);
    }
    // [left, right)
    TreeNode* balanceBSTHelper(const vector<int>& ans, int left, int right){
        if (left >= right) return nullptr;
        int rootIdx = (left + right)/2;
        TreeNode* root = new TreeNode(ans[rootIdx]);
        root->left = balanceBSTHelper(ans, left, rootIdx);
        root->right = balanceBSTHelper(ans, rootIdx + 1, right);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        // First extract all the values from the tree into an array by inorder traversal
        // The array will be a sorted array by trivial
        // Construct a BST from the array
        vector<int> ans;
        inorderTraversal(root, ans);
        return balanceBSTHelper(ans, 0, ans.size());
        
        
    }
};
