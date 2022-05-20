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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        ///Approach-01: BST Deletion
        //case-01: root is invalid
                // find the smallest node from right subtree and replace it with root
        //case-02: middle node is invalid
                // case-I: node has 1 child(left or right)
                // case-II: node has both child
        //case-03: leaf node is invalide
                // just set the node as null
        
    
        //Approach-02: Recursion
        /*
        if(!root) return root;
        
        if(root->val<low) return trimBST(root->right, low, high);
        if(root->val>high) return trimBST(root->left, low, high);
        
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        
        return root;
        */
        //Approach-03: Iterative
        
        //first fix the root
        while(root!=NULL){
            if(root->val<low) root = root->right;
            else if(root->val>high) root = root->left;
            else break;
        }
        
        if(root==NULL) return root;
        
        //fix the left subtree
        TreeNode* Left = root;
        while(Left->left!=NULL){
            if(Left->left->val<low) Left->left = Left->left->right;
            else Left = Left->left;
        }
        
        //fix the right subtree
        TreeNode* Right = root;
        while(Right->right!=NULL){
            if(Right->right->val>high) Right->right = Right->right->left;
            else Right = Right->right;
        }
        
        return root;
    }
};
