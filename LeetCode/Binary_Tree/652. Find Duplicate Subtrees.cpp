// 652. Find Duplicate Subtrees
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> res;
        unordered_map<string, vector<TreeNode*>> mp;

        serialize(root, mp);

        for(auto& m: mp){
           //cout<<m.first<<endl;
           if(m.second.size()>1) res.push_back(m.second[0]);
        }
        return res;
    }
private:
    string serialize(TreeNode* root, unordered_map<string, vector<TreeNode*>> &mp){
        if(!root) return "";
        string str = "("+serialize(root->left, mp)+to_string(root->val)+serialize(root->right, mp)+")";
        mp[str].push_back(root);
        return str;
    }
};