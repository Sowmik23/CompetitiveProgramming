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
    int ans = 0;
    int sumRootToLeaf(TreeNode* root) {
        
        string str = "";
        dfs(root, str);
        
        return ans;
    }
private:
    void dfs(TreeNode* root, string str){
        
        string x = to_string(root->val);
        str+=x;
        
        if(root->left==NULL and root->right==NULL) {
            //cout<<str<<endl;
            
            int x = 0;
            for(int i=0;i<str.size();i++){
                x+= pow(2, str.size()-i-1)*(str[i]-'0');
            }
            //cout<<x<<endl;
            ans+=x;
            
            return ;
        }
        
        
        if(root->left!=NULL) dfs(root->left, str);
        if(root->right!=NULL) dfs(root->right, str);
        
        str.pop_back();
    }
};
