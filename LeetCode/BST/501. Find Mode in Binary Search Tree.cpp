// 501. Find Mode in Binary Search Tree

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
    vector<int> findMode(TreeNode* root) {
      
        /*
        vector<int> res;
        inorder(root);

        int mxCnt = 0;
        for(auto& m: mp){
            if(mxCnt<m.second){
                res.clear();
                mxCnt = m.second;
                res.push_back(m.first);
            }
            else if(mxCnt==m.second) res.push_back(m.first);
        }
        return res;
        */

        //optimized space


        recursive(root);
        return res;


        //TODO: Approach 6: True Constant Space: Morris Traversal

    }
private:
    unordered_map<int, int> mp;
    void inorder(TreeNode* root){
        if(!root) return;
        mp[root->val]++;
        inorder(root->left);
        inorder(root->right);
    }

    vector<int> res;
    int mxCnt = 0;
    int currCnt = 0;
    int currNum = 0;
    void recursive(TreeNode* root){

        if(!root) return;
 
        recursive(root->left);
        
        if(root->val==currNum) currCnt++;
        else {
            currCnt = 1;
            currNum = root->val;
        }

        if(currCnt>mxCnt){
            res.clear();
            mxCnt = currCnt;
        }
        if(currCnt==mxCnt) res.push_back(root->val);

       
        recursive(root->right);
    }
};