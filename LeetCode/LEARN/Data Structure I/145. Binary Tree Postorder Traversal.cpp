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
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> res;
        
        //recursive version
        
        //recursivePostorder(root, res);
        
        
        //iterative version
        
        if(root==NULL) return {};
        stack<TreeNode*> stk;
        stack<int> tmp;
        
        stk.push(root);
        
        while(!stk.empty()){
            TreeNode* curr = stk.top();
            stk.pop();
            
            tmp.push(curr->val);
            
            
            if(curr->left!=NULL) stk.push(curr->left);
            if(curr->right!=NULL) stk.push(curr->right);
        }
        while(!tmp.empty()){
            res.push_back(tmp.top());
            tmp.pop();
        }
        
        
        return res;
    }
    
private:
    void recursivePostorder(TreeNode* root, vector<int> &res){
        
        if(root==NULL) return;
        recursivePostorder(root->left, res);
        recursivePostorder(root->right, res);
        
        res.push_back(root->val);
    }
};
