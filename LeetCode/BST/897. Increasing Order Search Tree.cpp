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
    TreeNode res=NULL;
    TreeNode* tmp = &res;
    
    TreeNode* increasingBST(TreeNode* root) {
        
        //iterative
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        
        while(!stk.empty() or curr!=NULL){
            while(curr!=NULL){
                stk.push(curr);
                curr = curr->left;
            }
            
            curr = stk.top();
            stk.pop();
            
            tmp->right = curr;
            curr->left = NULL;
            tmp = tmp->right;
            
            curr = curr->right;
        }
        
        return res.right;
        
        //recusive
       // recursive(root);
       // return res.right;
    }
private:
    
    void recursive(TreeNode* root){
        if(root==NULL) return;
        
        recursive(root->left);
       
      //  cout<<root->val<<endl;
        
        tmp->right = root;
        tmp = tmp->right;
        // root->left = NULL;
        
        
        recursive(root->right);
    }
};
