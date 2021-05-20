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
 
 ///Morris traversal: an ingenious O(n) in-place in-order traversal
class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode* cur = root;   ///Time: O(n), Memory: O(1)
        
        while(cur!=NULL){
            if(cur->left!=NULL){
                if(cur->right!=NULL){
                    TreeNode* next = cur->left;
                    if(next->right!=NULL){
                        while(next->right!=NULL){
                            next = next->right;
                        }
                    }
                    next->right = cur->right;
                }
                cur->right = cur->left;
                cur->left = NULL;
            }   
            cur = cur->right;
        }
    }
};
