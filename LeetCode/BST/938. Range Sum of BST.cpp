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
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        int sum = 0;
        
        Sum(root, low, high, sum);
        
        return sum;
    }
private:
    void Sum(TreeNode* root, int low, int high, int &sum){
        if(root==NULL) return;
        
        if(root->val>=low and root->val<=high) sum+=root->val;
        
        Sum(root->left, low, high, sum);
        Sum(root->right, low, high, sum);
    }
};
