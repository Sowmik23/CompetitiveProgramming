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
    int cnt = 0;
    int minCameraCover(TreeNode* root) {
        
        int val = recursive(root);
        //cout<<cnt<<" "<<val<<endl;
        return cnt+ (val==2 ? 1:0);
    }
private:
    //here 1 means: node is monitored
    // 2 means: node is not monitored
    // 3 means: node has camera
    int recursive(TreeNode* root){
        if(!root) return 1;
        
        int left = recursive(root->left);
        int right = recursive(root->right);
        
        if(left==1 and right==1) return 2;
        else if(left==2 or right==2){
            cnt++;
            return 3;
        }
        return 1;
    }
};
