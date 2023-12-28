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
    int minDiffInBST(TreeNode* root) {
        
        return dfs(root);
    }
private:
    int res = INT_MAX, prev = -1;
    int dfs(TreeNode* root){
        if(root->left) dfs(root->left);
        if(prev>=0) res = min(res, root->val-prev);
        prev = root->val;
        if(root->right) dfs(root->right);
        return res;
    }
};