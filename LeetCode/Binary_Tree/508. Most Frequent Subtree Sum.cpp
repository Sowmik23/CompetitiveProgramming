// 508. Most Frequent Subtree Sum
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        vector<int> res;
        unordered_map<int, int> mp;

        postOrderTraversal(mp, root);
        
        for(auto& m: mp){
            if(m.second==mxFreq) res.push_back(m.first);
        }

        return res;
    }
private:
    int mxFreq = 0;
    int postOrderTraversal(unordered_map<int, int> &mp, TreeNode* root){

        if(!root) return 0;
        int left = postOrderTraversal(mp, root->left);
        int right = postOrderTraversal(mp, root->right);
        
        mp[left+right+root->val]++;
        mxFreq = max(mxFreq, mp[left+right+root->val]);

        return root->val+left+right;
    }
};