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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root==NULL) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int> tmpres;
            
            for(int i=0;i<n;i++){
                TreeNode* tmp = q.front();
                q.pop();
                
                tmpres.push_back(tmp->val);
                if(i==n-1){
                    if(level%2==1){
                        res.push_back(tmpres);
                    }
                    else {
                        reverse(tmpres.begin(), tmpres.end());
                        res.push_back(tmpres);
                    }
                    level++;
                }
                
                if(tmp->left!=NULL) q.push(tmp->left);
                if(tmp->right!=NULL) q.push(tmp->right);
            }
        }
        
        return res;
    }
};
