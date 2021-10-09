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
        
        vector<int> res;
        
        
        //Recursive version
      //  recursiveInorder(root, res);
        
        
        //iterative version
        
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        
        
        while(!stk.empty() or curr!=NULL){
            while(curr!=NULL){
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            
            res.push_back(curr->val);
            
            curr = curr->right;
        }
        
        return res;
    }
private:
    void recursiveInorder(TreeNode* root, vector<int> &res){
        if(root==NULL) return;
        recursiveInorder(root->left, res);
        res.push_back(root->val);
        recursiveInorder(root->right, res);
    }
};
