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
    int pseudoPalindromicPaths (TreeNode* root) {

        unordered_map<int, int> mp;

        return recursive(root, mp);
    }
private:
    int cnt = 0;
    int recursive(TreeNode* root, unordered_map<int, int>&mp){
        if(!root) return 0;
        mp[root->val]++;

        if(root->left==nullptr and root->right==nullptr){
            cnt+=checkIfPseudoPalindrome(mp);
        }

        if(root->left) recursive(root->left, mp);
        if(root->right) recursive(root->right, mp);
        mp[root->val]--;

        return cnt;
    }
    int checkIfPseudoPalindrome(unordered_map<int, int> &mp){
        bool flag = false;
        for(auto& m:  mp){
            if(m.second%2) {
                if(flag==true) return 0;
                flag = true;
            }
        }
        return 1;
    }
};
