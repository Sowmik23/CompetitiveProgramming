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
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }
        
        ///recursive version
        //return isSymmetricRecursive(root->left, root->right);
        
        ///iterative version
        
        queue<TreeNode*> q1, q2;
        
        q1.push(root->left);
        q2.push(root->right);
        
        while(!q1.empty() and !q2.empty()){
            
            TreeNode* leftSubtree = q1.front();
            q1.pop();
            
            TreeNode* rightSubtree = q2.front();
            q2.pop();
            
            if(leftSubtree==NULL and rightSubtree==NULL) continue;
            if(leftSubtree==NULL or rightSubtree==NULL) return false;
            if(leftSubtree->val!=rightSubtree->val) return false;
            
            q1.push(leftSubtree->left);
            q1.push(leftSubtree->right);
            
            q2.push(rightSubtree->right);
            q2.push(rightSubtree->left);
        }
        
        return true;
    }
    
private:
    bool isSymmetricRecursive(TreeNode* a, TreeNode* b){
        if(a==NULL and b==NULL) return true;
        else if(a==NULL or b==NULL) return false;
        else if(a->val!=b->val) return false;
        return isSymmetricRecursive(a->left, b->right) and isSymmetricRecursive(a->right, b->left);
    }
};
