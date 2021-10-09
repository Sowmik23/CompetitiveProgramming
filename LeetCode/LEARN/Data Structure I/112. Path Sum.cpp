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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        //Approach-01: Recursive
        /*
        if(root==NULL) return false;
        if(root->val==targetSum and  root->left==NULL and root->right==NULL) return true;
        
        return hasPathSum(root->left, targetSum-root->val) or hasPathSum(root->right, targetSum-root->val); */
        
        //Approach-02: Iterative
        
        if(root==NULL) return false;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, root->val});
        
        while(!stk.empty()){
            pair<TreeNode*, int> top = stk.top();
            stk.pop();
            
            TreeNode* t = top.first;
            int val = top.second;
            
            if(t->left==NULL and t->right==NULL and val==targetSum) return true;
            
            if(t->right!=NULL) stk.push({t->right, val + t->right->val});
            if(t->left!=NULL) stk.push({t->left, val + t->left->val});
           
        }
        
        return false;
    }
};
