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
    vector<TreeNode*> generateTrees(int n) {
        
        //Time: O(Cn)
        //Space: O(Cn)
        
        return genTrees(1, n);
    }
    
private:
    vector<TreeNode*> genTrees(int left, int right){
        if(left>right) return {NULL};
        
        vector<TreeNode*> res;
        for(int root=left;root<=right;root++){
            vector<TreeNode*> leftTree = genTrees(left, root-1);
            vector<TreeNode*> rightTree = genTrees(root+1, right);
            
            for(auto& l: leftTree){
                for(auto& r: rightTree){
                    TreeNode* node = new TreeNode(root);
                    node->left = l;
                    node->right = r;
                    
                    res.push_back(node);
                }
            }
        }
        
        return res;
    }
};
