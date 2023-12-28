// 863. All Nodes Distance K in Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        //using two bfs
        vector<int> res;
        unordered_map<int, TreeNode*> parent;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto top = q.front();
                q.pop();
                if(top->left){
                    parent[top->left->val] = top;
                    q.push(top->left);
                }
                if(top->right){
                    parent[top->right->val] = top;
                    q.push(top->right);
                }
            }
        }

        unordered_map<int, int> visited;
        q.push(target);
        while(k-- and !q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto top = q.front();
                q.pop();

                visited[top->val] = 1;

                //traverse to bottom
                if(top->left and !visited[top->left->val]){
                    q.push(top->left);
                }
                if(top->right and !visited[top->right->val]){
                    q.push(top->right);
                }

                //traverse to up
                if(parent[top->val] and !visited[parent[top->val]->val]){
                    q.push(parent[top->val]);
                }
            }
        }

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            res.push_back(top->val);
        }
        return res;
    }
};


