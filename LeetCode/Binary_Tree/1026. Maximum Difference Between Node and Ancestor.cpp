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
    int res = 0;
    int maxAncestorDiff(TreeNode* root) {
        
        dfs_visit(root, root->val, root->val);    
        
        return res;
    }
private:
    int dfs_visit(TreeNode* root, int mx, int mn){
        if(root==NULL) return 0;
        
        int curr_max = max( abs(mx-root->val), abs(mn-root->val) );
        res = max(res, curr_max);
        
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        
        dfs_visit(root->left, mx, mn);
        dfs_visit(root->right, mx, mn);
        
        return res;
    }
};
