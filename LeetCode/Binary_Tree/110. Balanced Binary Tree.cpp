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
    bool ans;
    bool isBalanced(TreeNode* root) {

        if(!root) return true;
        ans = true;
        int tmp = recursive(root);
        return ans;
    }
private:
    int recursive(TreeNode* root){

        if(!root) return 0;
        if(!ans) return 0;

        int l = recursive(root->left);
        int r = recursive(root->right);

        if(abs(l-r)>1) ans = false;
        return 1+max(l, r);
    }
};
