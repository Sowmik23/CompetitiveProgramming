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
    int totaltiledSum = 0;
    int findTilt(TreeNode* root) {
        
        //use post order traversal logic
        
        tiltSum(root);
        return totaltiledSum;
    }
    
private:
    int tiltSum(TreeNode* root){
        if(root==NULL) return 0;
        
        int leftTreeSum = tiltSum(root->left);
        int rightTreeSum = tiltSum(root->right);
        
        totaltiledSum += abs(leftTreeSum-rightTreeSum);
        
        return root->val + leftTreeSum+rightTreeSum;
    }
};
