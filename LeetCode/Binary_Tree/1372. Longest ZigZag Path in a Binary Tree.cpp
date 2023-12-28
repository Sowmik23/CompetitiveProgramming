// 1372. Longest ZigZag Path in a Binary Tree
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
    int longestZigZag(TreeNode* root) {
        
        if(!root) return 0;
        dfs(root, 0, -1); //left
        dfs(root, 0, 1); //right
        return mxLen;
    }
private:
    int mxLen = 0;
    void dfs(TreeNode* root, int visitedNode, int direction){
        if(!root) return;

        mxLen = max(mxLen, visitedNode);
        if(direction==-1) {
            dfs(root->right, 1, -1);
            dfs(root->left, visitedNode+1, 1);
        }
        if(direction==1) {
            dfs(root->left, 1, 1);
            dfs(root->right, visitedNode+1, -1);
        }
    }
};