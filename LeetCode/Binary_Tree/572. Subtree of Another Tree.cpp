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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(!root) return false;
        
        //in case of, same tree
        if(dfs(root, subRoot)) return true;
        
        return  isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool dfs(TreeNode* root, TreeNode* subRoot){
        
        if(!subRoot and !root) return true;
        if(!subRoot or !root) return false;
        
        if(root->val!=subRoot->val) return false;
        
        return dfs(root->left, subRoot->left) && dfs(root->right, subRoot->right);
    }
};
