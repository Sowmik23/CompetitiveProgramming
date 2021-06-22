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
    vector<int> inorderTraversal(TreeNode* root) {
     
        ///resurcive method
//         vector<int> res;
//         recursion(res, root);
        
//         return res;
        
        
        ///iterative method:
        vector<int> res;
        
        if(!root) return res;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        bool goRight = false;
        
        while(!stk.empty()){
            
            TreeNode* tmp = stk.top();
            if(goRight){
                res.push_back(tmp->val);
                stk.pop();
                if(tmp->right!=NULL){
                    stk.push(tmp->right) ;
                    goRight = false;
                }
            }
            else {
                if(tmp->left!=NULL){
                    stk.push(tmp->left);
                }
                else goRight = true;
            }
        }
        
        return res;
    }
private:
    void recursion(vector<int> &res, TreeNode* root) { 
        if(root==NULL) return;
        if(root->left!=NULL) recursion(res, root->left);
        res.push_back(root->val);
        if(root->right!=NULL) recursion(res, root->right);
    }
};
