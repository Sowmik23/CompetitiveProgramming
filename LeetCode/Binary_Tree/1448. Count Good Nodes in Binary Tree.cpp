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
    int goodNodes(TreeNode* root) {

        return inOrder(root, root->val);
    }
private:
    int cnt = 0;
    int inOrder(TreeNode* root, int mx){
        if(!root) return cnt;

        mx = max(mx, root->val);
        cnt = inOrder(root->left, mx);

        if(root->val>=mx) cnt++;

        mx = max(mx, root->val);
        cnt = inOrder(root->right, mx);

        return cnt;
    }
};
