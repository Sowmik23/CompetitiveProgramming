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
    int deepestLeavesSum(TreeNode* root) {
        
        //approach-01: DFS
        
        if(!root) return 0;
       
        TreeNode* tmp = root;
        int h = getHeight(tmp);
        cout<<h<<endl;
        
        return dfs(root, 0, h);
        
        //approach-02: apply level order: BFS
        //and sum the last level's node value
        /*
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        
        int sum = 0, res = 0;
        
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* top = q.front();
                q.pop();
                
                sum+=top->val;
                
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            res = sum;
            sum = 0;
        }
    
        return res;
      */  
    }
private:
    int getHeight(TreeNode* root){
        
        if(!root) return 0;
        
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        return max(left, right)+1;
    }
    
     
     int dfs(TreeNode* root, int level, int h){
        
        if(!root) return 0;
         
        if(level==h-1) return root->val;
        //cout<<root->val<<" "<<level<<endl;
        
        return dfs(root->left, level+1, h) + dfs(root->right, level+1, h);
    }
};
