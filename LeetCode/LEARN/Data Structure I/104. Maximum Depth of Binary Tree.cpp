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
    int maxDepth(TreeNode* root) {
        
     //The maximum depth is the height of a binary tree
        
        if(root==NULL) return 0;
        
        int leftHeight = 1 + maxDepth(root->left);
        int rightHeight = 1 + maxDepth(root->right);
        
        return max(leftHeight, rightHeight);
    }
};
