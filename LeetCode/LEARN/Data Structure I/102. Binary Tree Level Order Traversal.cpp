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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL) return {};
        
        vector<vector<int>> res;
        vector<int> tmp;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* top = q.front();
                q.pop();
                
                if(top!=NULL){
                    tmp.push_back(top->val);
                }
                if(top->left!=NULL) q.push(top->left);
                if(top->right!=NULL) q.push(top->right);
            }
            res.push_back(tmp);
            tmp = vector<int> ();    
        }
        
        return res;
    }
};
