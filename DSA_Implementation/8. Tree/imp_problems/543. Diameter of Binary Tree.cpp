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
    int diameterOfBinaryTree(TreeNode* root) {
        
        int d = 0;
        diameter(root, d);
        
        return d;
    }
    
private:
    int diameter(TreeNode* root, int &d){
        
        if(root==NULL) return 0;
        
        int leftDiameter = diameter(root->left, d);
        int rightDiameter = diameter(root->right, d);
        
        d = max(d, leftDiameter+rightDiameter);
        
        return max(leftDiameter, rightDiameter)+1;
    }
};
