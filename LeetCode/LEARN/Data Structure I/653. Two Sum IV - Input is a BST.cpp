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
    bool findTarget(TreeNode* root, int k) {
        
        unordered_map<int, int> check;
        
        if(root==NULL) return false;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()){
            
            TreeNode* top = stk.top();
            stk.pop();
            
            if(check.find(k - top->val)!=check.end()) return true;
            else check[top->val] = k - top->val;
            
            if(top->left!=NULL) stk.push(top->left);
            if(top->right!=NULL) stk.push(top->right);
        }
        
        return false;
    }
};
