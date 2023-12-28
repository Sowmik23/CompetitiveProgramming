// 2196. Create Binary Tree From Descriptions
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int, pair<int, int>> mp;
        unordered_map<int, int> childs;

        for(auto& description: descriptions){
            if(description[2]==1) {
                int prevRight = mp[description[0]].second ? mp[description[0]].second : 0;
                mp[description[0]] = {description[1], prevRight};
            }
            else {
                int prevLeft = mp[description[0]].first ? mp[description[0]].first : 0;
                mp[description[0]] = {prevLeft, description[1]};
            }
            childs[description[1]]++;
        }

        int root = -1;
        for(auto& m: mp){
            if(childs.find(m.first)==childs.end()) root = m.first;
        }

        TreeNode* rt = new TreeNode(root);
        return dfs(rt, root, mp);
    }
private:
    TreeNode* dfs(TreeNode* rt, int rootVal, unordered_map<int, pair<int, int>> &mp){

        //if(rootVal==0) return nullptr;
        
        if(mp.find(rootVal)!=mp.end()){

            int left = mp[rootVal].first ? mp[rootVal].first : 0;
            int right = mp[rootVal].second ? mp[rootVal].second : 0;
            //cout<<rootVal<<" "<<left<<" "<<right<<endl;

            rt->left = left==0 ? nullptr : new TreeNode(left);
            rt->right = right==0 ? nullptr : new TreeNode(right);
            
            if(left) dfs(rt->left, left, mp);
            if(right) dfs(rt->right, right, mp);
        }
       return rt;
    }
};