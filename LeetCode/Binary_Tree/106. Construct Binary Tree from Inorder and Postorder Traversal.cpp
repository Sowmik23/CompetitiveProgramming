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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        return splitTree(inorder, postorder, mp, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
private:
    TreeNode* splitTree(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mp, int inStart, int inEnd, int postStart, int postEnd){
        
        if(inStart>inEnd or postStart>postEnd) return NULL;
        
        int root_val = postorder[postEnd];
        int rootIndex = mp[root_val];
        
        TreeNode* root = new TreeNode(root_val);
        
        root->left = splitTree(inorder, postorder, mp, inStart, rootIndex-1, postStart, postStart+rootIndex-inStart-1);
        
        root->right = splitTree(inorder, postorder, mp, rootIndex+1, inEnd, postStart+rootIndex-inStart, postEnd-1);
        
        
        return root;
    }
};
