// 2641. Cousins in Binary Tree II
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        //Time: O(n)
        //Space: O(n)

        /*
        //DFS(2) Solution
        unordered_map<int, int> mp;

        //pre-calculate level sum
        int level = 0;
        dfs(root, level, mp);

        level = 1;
        return dfs2(root, new TreeNode(0), level, mp);
        */

        //BFS two Solution
        unordered_map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);
        mp[0] = root->val;
        int level = 1;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto top = q.front();
                q.pop();
                
                if(top->left) {
                    q.push(top->left);
                    mp[level]+=(top->left->val);
                }
                if(top->right) {
                    q.push(top->right);
                    mp[level]+=(top->right->val);
                }
            }
            level++;
        }

        level = 1;
        q.push(root);
        root->val = 0;

        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto top = q.front();
                q.pop();

                int left = top->left ? top->left->val : 0;
                int right = top->right ? top->right->val : 0;
                int sum_of_all_cousins = mp[level] - (left+right);
                if(top->left){
                    q.push(top->left);
                    top->left->val = sum_of_all_cousins;
                }
                if(top->right){
                    q.push(top->right);
                    top->right->val = sum_of_all_cousins;
                }
            }
           level++;
        }
        return root;
    }
private:
    void dfs(TreeNode* root, int level, unordered_map<int, int> &mp){
        if(!root) return;
        mp[level]+=root->val;
        dfs(root->left, level+1, mp);
        dfs(root->right, level+1, mp);
    }
    TreeNode* dfs2(TreeNode* root, TreeNode* nroot, int level, unordered_map<int, int> &mp){
        //if(!root) return;
        int left = root->left ? root->left->val : 0;
        int right = root->right ? root->right->val : 0;

        int sum_of_all_cousins = mp[level] - (left+right);
        if(root->left) {
            nroot->left = new TreeNode(sum_of_all_cousins);
            dfs2(root->left, nroot->left, level+1, mp);
        }
        if(root->right){
            nroot->right = new TreeNode(sum_of_all_cousins);
            dfs2(root->right, nroot->right, level+1, mp);
        }
        return nroot;
    }
};
