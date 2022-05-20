/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(!original) return NULL;
        if(original==target) return cloned;
        
        if(original->left) res = getTargetCopy(original->left, cloned->left, target);
        if(res==target) return res;
        if(original->right) return getTargetCopy(original->right, cloned->right, target);
        
        return res;
    }
};
