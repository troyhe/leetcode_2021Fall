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
    
    vector<TreeNode*> helper(int start, int end){
        // EFFECT: Generate BSTs for integers in the intervakl [start, end]
        vector<TreeNode*> ans;
        if (start > end){
            ans.push_back(nullptr);
            return ans;
        }
        for (int i = start; i <= end; i++){
            vector<TreeNode*> left = helper(start, i - 1);
            vector<TreeNode*> right = helper(i + 1, end);
            for (TreeNode* l: left){
                for (TreeNode* r: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        // To generate a tree, we should first pick an element as a root. Then all the lements in the left subtree will be smaller than the root element while all the elements in the right subtree will be greater than that. 
        // We would like to employ a helper, which makes it friendly to paly with DP. 
        return helper(1, n);
    }
};
