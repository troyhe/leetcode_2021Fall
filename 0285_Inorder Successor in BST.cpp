/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    // TreeNode* successor;
    // void helper()
    TreeNode* leftmostChild(TreeNode* root){
        // root should not be null
        while (root->left) root = root->left;
        return root;
    }
    
    TreeNode* successor;
    void findSuccessor(TreeNode* root, TreeNode* p){
        if (!root) return;
        // if (root->val == p->val) return;
        if (root->val > p->val){
            successor = root;
            findSuccessor(root->left, p);
        } else {
            findSuccessor(root->right, p);
        }
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // Case 1: p has a right child, which means the inorder successor of p must be the leftmost node in the right subtree of p
        if (!p) return nullptr;
        if (p->right) return leftmostChild(p->right);
        
        // Case 2: p does not have a right child, the successor will be in another branch.
        // We should utilize the feature of BST
        successor = nullptr;
        findSuccessor(root, p);
        return successor;
        
    }
};
