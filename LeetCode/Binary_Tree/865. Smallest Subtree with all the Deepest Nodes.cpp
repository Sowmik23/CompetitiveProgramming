// 865. Smallest Subtree with all the Deepest Nodes
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        int depth = findDepth(root);

        postOrder(root, 0, depth);
        return res;
    }
private:
    TreeNode* res = nullptr;
    int postOrder(TreeNode* root, int level, int depth){
        if(!root) return level;

        int left = postOrder(root->left, level+1, depth);
        int right = postOrder(root->right, level+1, depth);
        if(left==depth and right==depth){
            res = root;
        }
        return max(left, right);
    }
    int findDepth(TreeNode* root){
        if(!root) return 0;
        return max(findDepth(root->left), findDepth(root->right))+1;
    }
};