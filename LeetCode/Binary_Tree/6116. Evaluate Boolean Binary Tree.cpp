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
    vector<int> res;
    
    bool evaluateTree(TreeNode* root) {
        
       return dfs(root);
    }
private:
    bool dfs(TreeNode* root){
        
        if(root->val==0 or root->val==1) return root->val;
        
        int left = -1;
        int right = -1;

        if(root->left) left = dfs(root->left);
        
        if(root->right) right = dfs(root->right);
        
        if(left!=-1 and right!=-1){
            if(root->val==2) return left or right;
            
            return left and right;
        }
        
        return left and right;
    }
};
