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
    int sumNumbers(TreeNode* root) {
        
        if(!root) return 0;
        calculate(root, "");
        return res;
    }
private:
    int res;
    void calculate(TreeNode* root, string x){

        if(!root->left and !root->right) {
            x+=to_string(root->val);
            res+=stoi(x);
        }

        if(root->left) calculate(root->left, x+to_string(root->val));
        if(root->right) calculate(root->right, x+to_string(root->val));
    }
};


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
    int sumNumbers(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, root->val});
        int sum = 0;
        
        while(!stk.empty()){
            pair<TreeNode*, int> top = stk.top();
            stk.pop();
            
            if(top.first->left==NULL and top.first->right==NULL){
                //cout<<"first: "<<top.first->val<<" "<<top.second<<endl;
                sum+=top.second;
            }
            
            if(top.first->left!=NULL){
                stk.push({top.first->left, top.second*10+top.first->left->val});
            }
            if(top.first->right!=NULL){
                stk.push({top.first->right, top.second*10+top.first->right->val});
            }
        }
        
        return sum;
    }
};
