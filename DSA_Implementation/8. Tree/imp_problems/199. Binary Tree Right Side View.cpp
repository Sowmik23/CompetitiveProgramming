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
    vector<int> rightSideView(TreeNode* root) {
        
        
        ///BFS solution
        /*
        if(root==NULL) return {};
        
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
        
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* top = q.front();
                q.pop();
                
                if(i==n-1) res.push_back(top->val);
                if(top->left!=NULL) q.push(top->left);
                if(top->right!=NULL) q.push(top->right);   
            }
        }
        
        return res;
        */
        
        
        ////DFS Solution
        vector<int> res;
        
        int level = 0;
        rightView(root, level, res);
        
        return res;
    }
    
private:
    void rightView(TreeNode* root, int level, vector<int> &res){
        
        if(root==NULL) return;
        if(res.size()==level) res.push_back(root->val);
        
        rightView(root->right, level+1, res);
        rightView(root->left, level+1, res);
    }
};
