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
    int sumOfLeftLeaves(TreeNode* root) {
        
        int sum = 0;
        if(root==NULL) return 0;
        
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, -1});
        
        while(!stk.empty()){
            pair<TreeNode*, int> top = stk.top();
            stk.pop();
            
            if(top.first->left==NULL and top.first->right==NULL){
                if(top.second==0) sum+=top.first->val;
            }
            
            if(top.first->left!=NULL) stk.push({top.first->left, 0});
            if(top.first->right!=NULL) stk.push({top.first->right, 1});
        }
        
        return sum;
    }
};
