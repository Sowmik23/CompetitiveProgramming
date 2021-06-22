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
            mp[inorder[i]]  = i;
        }
        
        return splitTree(preorder, inorder, mp, 0, 0, inorder.size()-1);
    }
    
private:
    TreeNode* splitTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp, int pix, int left, int right){
        
        int rval = preorder[pix];
        int mid = mp[rval];
        
        TreeNode* root = new TreeNode(rval);
        
        if(mid>left){
            root->left = (splitTree(preorder, inorder, mp, pix+1, left, mid-1));
        }
        if(mid<right){
            root->right = splitTree(preorder, inorder, mp, pix+mid-left+1, mid+1, right);
        }
        
        return root;
    }
};
