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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
     
        ///Approach-01: recursion
        /*
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        
        root1->val = root1->val + root2->val;
        
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
        */
        
        ///Approach-02: iterative
        
        if(root1==NULL) return root2;
        if(root2==NULL) return root1;
        
        stack<pair<TreeNode*, TreeNode*>> stk;
        stk.push({root1, root2});
        
        while(!stk.empty()){
            pair<TreeNode*, TreeNode*> top = stk.top();
            TreeNode* top_left = top.first;
            TreeNode* top_right = top.second;
            stk.pop();
            
            if(top.first==NULL or top.second==NULL) continue;
            
            top.first->val += top.second->val;
            
            if(top.first->left==NULL){
                top.first->left = top.second->left;
            }
            else {
                stk.push({top.first->left, top.second->left});
            }
            
            if(top.first->right ==NULL){
                top.first->right = top.second->right;
            }
            else {
                stk.push({top.first->right, top.second->right});
            }
        }
        
        return root1;
    }
};
