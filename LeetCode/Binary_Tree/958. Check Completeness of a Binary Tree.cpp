// 958. Check Completeness of a Binary Tree

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
    bool isCompleteTree(TreeNode* root) {
        
        //recursive
        //use the property of complete binary tree

        int n = countTotalNodes(root);
        return isComplete(root, 0, n);

        //bfs
        /*
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto top = q.front();
                q.pop();
    
                if(!top) {
                    flag = true;
                }
                else {
                    if(flag) return false;
                    q.push(top->left);
                    q.push(top->right);
                }
            }
        }
        return true;
        */
    }
private:
    bool isComplete(TreeNode* root, int idx, int n){
        if(!root) return true;
        if(idx>=n) return false;

        return isComplete(root->left, 2*idx+1, n) and isComplete(root->right, 2*idx+2, n);
    }
    int countTotalNodes(TreeNode* root){
        if(!root) return 0;
        return 1+countTotalNodes(root->left) + countTotalNodes(root->right);
    }
};