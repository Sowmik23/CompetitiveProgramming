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
    ///iterative version:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//         if(root==NULL) return root;
        
//         while(root!=NULL){
//             if(root->val > p->val and root->val > q->val){
//                 root = root->left;
//             }
//             else if(root->val < p->val and root->val < q->val){
//                 root = root->right;
//             }
//             else break;
//         }
        
//         return root;
//     }
    
    ////recursive version
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL) return root;
        
        if(root->val > p->val and root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        if(root->val < p->val and root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        
        return root;
    }
};
