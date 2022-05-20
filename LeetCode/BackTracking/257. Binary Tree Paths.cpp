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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res;
        string str = "";
        
        findAllPaths(root, res, str);
        return res;
    }
private:
    void findAllPaths(TreeNode* root, vector<string> &res, string str){
        
        str+=to_string(root->val);
        if(root->left==NULL and root->right==NULL){
            res.push_back(str);
        }
        else {
            str+="->";
            if(root->left) findAllPaths(root->left, res, str);
            if(root->right) findAllPaths(root->right, res, str);
        }
    }
};
