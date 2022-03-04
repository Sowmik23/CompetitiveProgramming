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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        
        int res = 0;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
         
            int init = q.front().first;
            int first, last;
            
            for(int i=0;i<n;i++){
                auto top = q.front();
                TreeNode* node = top.second;
                q.pop();
                
                int index = top.first - init;
                if(i==0) first = index;
                if(i==n-1) last = index;
                
                if(node->left) q.push({(long)2*index+1, node->left});
                if(node->right) q.push({(long)2*index+2, node->right});
            }
            res = max(res, last-first+1);
        }
        
        return res;
    }
};
