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
    int kthSmallest(TreeNode* root, int k) {
        
        //approaches: 
        //inorder traversal
        //or using min priority queue
        
        
        ///approach: inorder traversal: iterative version
        /*stack<TreeNode*> stk;
        int cnt = 0;
        TreeNode* curr = root;
        
        while(curr!=NULL or !stk.empty()){
            while(curr!=NULL){
                stk.push(curr);
                curr = curr->left;
            }
            
            curr = stk.top();
            stk.pop();
            cnt++;  
            if(cnt==k) return curr->val;
            
            curr = curr->right;
        }
        return INT_MAX;
        */
        
        //recursive version
        vector<int> tmp;
        smallest(root, k, tmp);
        return tmp.at(k-1);
    }
private:
    void smallest(TreeNode* root, int k, vector<int> &tmp){
        
        if(root->left!=NULL) smallest(root->left, k, tmp);
        
        tmp.push_back(root->val);
        
        if(root->right!=NULL) smallest(root->right, k, tmp);
    }
};
