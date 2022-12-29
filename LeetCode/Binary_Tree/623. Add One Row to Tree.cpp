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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(depth==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            node->right = nullptr;
            return node;
        }

        recursive(root, val, depth,  1);
        return root;
    }
private:
    void recursive(TreeNode* root, int val, int depth, int currDepth){

        if(!root) return;
        if(currDepth==depth-1){
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            TreeNode* newLeftNode = new TreeNode(val);
            root->left = newLeftNode;
            newLeftNode->left = left;
            newLeftNode->right = nullptr;
            TreeNode* newRightNode = new TreeNode(val);
            root->right = newRightNode;
            newRightNode->right= right;
            newRightNode->left = nullptr;
        }

        recursive(root->left, val, depth, currDepth+1);
        recursive(root->right, val, depth, currDepth+1);
    }
};
