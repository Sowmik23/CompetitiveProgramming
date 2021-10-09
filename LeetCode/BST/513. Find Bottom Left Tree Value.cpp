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
    int findBottomLeftValue(TreeNode* root) {
        
        
        ///Approach: Level Order Traversal
        if(root==NULL) return 0;
        
       // vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* LeftMost;
        
        while(!q.empty()){
            int n = q.size();
            LeftMost = q.front();
            for(int i=0;i<n;i++){
                TreeNode* top = q.front();
                q.pop();
                
                // if(top!=NULL){
                //     if(i==0) res.push_back(top->val);
                // }
                if(top->left!=NULL) q.push(top->left);
                if(top->right!=NULL) q.push(top->right);
            }
        }
        
        //return res[res.size()-1];
        return LeftMost->val;
    }
};
