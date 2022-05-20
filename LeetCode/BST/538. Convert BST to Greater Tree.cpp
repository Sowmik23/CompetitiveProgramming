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
    TreeNode* convertBST(TreeNode* root) {
        
        //Approach: iterative
        
        if(!root) return root;
        
        stack<TreeNode*> stk;
        stk.push(root);
        int val = 0;
        
        while(!stk.empty()){
            TreeNode* top = stk.top();
            while(top->right!=NULL){
                top = top->right;
                stk.push(top);
            }
            
            top = stk.top();
            val += top->val;
            cout<<val<<endl;
            
            //set sum value in this node
            top->val = val;
            
            
            if(top->left!=NULL){
                stk.push(top->left);
            }
            else {
                val += stk.top()->val;
                stk.pop();
            }
        }
        
        return root;
        
        
        //Approach: Recursive
        //return recursive(root);
    }
private:
    int val = 0;
     TreeNode* recursive(TreeNode* root){
         if(!root) return root;
         
         recursive(root->right);
         val += root->val;
         
         root->val = val;
         
         recursive(root->left);
         
         return root;
     }
};
