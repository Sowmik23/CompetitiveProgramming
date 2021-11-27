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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        unordered_map<int, int> mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        return splitTree(preorder, inorder, mp, 0, preorder.size()-1);
    }
private:
    int rootIndex =0;
    TreeNode* splitTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp, int left, int right){
        
        if(left>right) return NULL;
        int root_val = preorder[rootIndex++];
        
        TreeNode* root = new TreeNode(root_val);
        
        root->left = splitTree(preorder, inorder, mp, left, mp[root_val]-1);
        root->right = splitTree(preorder, inorder, mp, mp[root_val]+1, right);
        
        return root;
    }
};
