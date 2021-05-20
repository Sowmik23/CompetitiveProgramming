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
        
        vector<vector<int>> res;
        vector<int> tmp;
        
        if(root==NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(q.size()>1){
            TreeNode* top = q.front();
            q.pop();
            
            if(top==NULL){
                q.push(NULL);
                res.push_back(tmp);
                tmp = vector<int> ();
            }
            else {
                if(top->left!=NULL)  q.push(top->left);
                if(top->right!=NULL) q.push(top->right);
                
                tmp.push_back(top->val);
            }
        }
        
        res.push_back(tmp);
        
        return res;
    }
};
