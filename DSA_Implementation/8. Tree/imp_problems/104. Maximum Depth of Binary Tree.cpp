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
    int maxDepth(TreeNode* root) {
        
        ///DFS solution
//         if(root==NULL) return NULL;
        
//         int leftDepth = maxDepth(root->left);
//         int rightDepth = maxDepth(root->right);
        
//         if(leftDepth>rightDepth) return leftDepth + 1;
//         else return rightDepth + 1;
    
        ///BFS solution
        
        if(root==NULL) return 0;
        
        int res =  0;
        queue<TreeNode*>  q;
        q.push(root);
        
        while(!q.empty()){
            res++;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* top = q.front();
                q.pop(); 
                
                if(top->left!=NULL) q.push(top->left);
                if(top->right!=NULL) q.push(top->right);
            }
        }
        
        return res;
    }
};
