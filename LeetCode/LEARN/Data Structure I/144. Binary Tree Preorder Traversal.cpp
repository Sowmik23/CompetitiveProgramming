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
    vector<int> preorderTraversal(TreeNode* root) {
        
        
        ///Recursive version
        vector<int> res;
        recursivePreorder(root, res);
        return res;
        
        
        //Iterative version
      /*  stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* curr = root;
        
        while(!stk.empty()){
            if(curr!=NULL){
                res.push_back(curr->val);
                if(curr->right!=NULL){
                    stk.push(curr->right);
                }
                curr = curr->left;
            }
            else {
                curr = stk.top();
                stk.pop();
            }
        }
        
        return res;
        */
    }
private:
    void recursivePreorder(TreeNode* root, vector<int> &res){
        if(root==NULL) return;

        res.push_back(root->val);
        recursivePreorder(root->left, res);
        recursivePreorder(root->right, res);
    }
};
