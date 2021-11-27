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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> res;
        vector<int> tmp;
        if(!root) return res;
        
        findPaths(root, targetSum, res, tmp);
        
        return res;
    }
private:
    void findPaths(TreeNode* root, int targetSum, vector<vector<int>> &res, vector<int> &tmp){
        if(!root) return ;
        tmp.push_back(root->val);
        if(root->left==NULL and root->right==NULL and targetSum==root->val){
            res.push_back(tmp);
        } 
        
        if(root->left) findPaths(root->left, targetSum-root->val, res, tmp);
        if(root->right) findPaths(root->right, targetSum-root->val, res, tmp);
        tmp.pop_back();
    }
};
