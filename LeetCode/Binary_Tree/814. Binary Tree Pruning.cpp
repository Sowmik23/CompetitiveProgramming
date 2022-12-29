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
    TreeNode* pruneTree(TreeNode* root) {

        return postOrder(root)==1 ? root : nullptr;
    }
private:
    int postOrder(TreeNode* root){
        if(!root) return 0;

        int left = postOrder(root->left);
        int right = postOrder(root->right);

        if(left==0) root->left = NULL;
        if(right==0) root->right = NULL;

        return root->val==1 or left or right;
    }
};
