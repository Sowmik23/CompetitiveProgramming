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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> res;
        unordered_map<int, vector<pair<int, int>>> mp;

        dfs(root, mp, 0, 0);

        int mn = INT_MAX, mx = INT_MIN;
        for(auto& i: mp){
            mn = min(mn, i.first);
            mx = max(mx, i.first);
        }
        for(int i=mn;i<=mx;i++){
            vector<pair<int, int>> tmp = mp[i];

            sort(tmp.begin(), tmp.end(), [](auto& a, auto& b){
                if(a.first==b.first) return a.second<b.second;
                return a.first<b.first;
            });

            vector<int> tmp1;
            for(auto& j: tmp) tmp1.push_back(j.second);

            res.push_back(tmp1);
        }

        return res;
    }
private:
    void dfs(TreeNode* root, unordered_map<int, vector<pair<int, int>>> &mp, int i, int j){

        mp[j].push_back({i, root->val});
        if(!root->left and !root->right) return;

        if(root->left) dfs(root->left, mp, i+1, j-1);
        if(root->right) dfs(root->right, mp, i+1, j+1);

        return;
    }
};
