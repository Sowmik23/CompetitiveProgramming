// 606. Construct String from Binary Tree

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
    string tree2str(TreeNode* root) {
        
        string str = "";
        preOrder(root, str);
        return str;
    }
private:
    void preOrder(TreeNode* root, string &str){
        
        if(!root) return;

        str+=to_string(root->val);
        if(root->left or root->right){
            str+="(";
            preOrder(root->left, str);
            str+=")";
        }
        if(root->right){
            str+="(";
            preOrder(root->right, str);
            str+=")";
        }
    }
};