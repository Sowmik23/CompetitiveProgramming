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
    TreeNode* invertTree(TreeNode* root) {
     
        ///Approach-01: Recursion
        /*
        if(root==NULL) return NULL;
        swap(root->left,  root->right);
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
        */
        
        ///Approach-02: Iterative
        if(root==NULL) return NULL;
        
        stack<TreeNode*> stk;
        stk.push(root);
            
        while(!stk.empty()){
            TreeNode* tmp = stk.top();
            stk.pop();
            
            swap(tmp->left, tmp->right);
            
            if(tmp->left!=NULL) stk.push(tmp->left);
            if(tmp->right!=NULL) stk.push(tmp->right);
        }
        
        return root;
    }
};
