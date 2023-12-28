// 1123. Lowest Common Ancestor of Deepest Leaves
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        if(!root->left and !root->right) return root;
        int depth = findDepth(root);
        //cout<<depth<<endl;

        
        findDeepestAncestor(root, 0, depth);
        return res;
    }
private:
    int findDepth(TreeNode* root){
        if(!root) return 0;
        return max(findDepth(root->left), findDepth(root->right))+1;
    }
    TreeNode* res = nullptr;
    int findDeepestAncestor(TreeNode* root, int h, int depth){
        if(!root) return h;
        
        int left = findDeepestAncestor(root->left, h+1, depth);
        int right = findDeepestAncestor(root->right, h+1, depth);

        if(left==depth and right==depth){
            res = root;
        }
        return max(left, right);
    }
};