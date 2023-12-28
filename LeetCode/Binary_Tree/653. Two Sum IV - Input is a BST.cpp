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
    bool findTarget(TreeNode* root, int k) {

        unordered_map<int, int> mp;

        stack<TreeNode*> stk;
        TreeNode* curr = root;

        while(curr or !stk.empty()){
            while(curr){
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            if(mp.find(k-curr->val)!=mp.end()) return true;
            mp[curr->val]  = 1;
            stk.pop();
            curr = curr->right;
        }
        return false;
    }
};
