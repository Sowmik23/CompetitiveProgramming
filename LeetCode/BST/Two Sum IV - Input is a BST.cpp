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
    
    unordered_set<int> ust;
    
    bool findTarget(TreeNode* root, int k) {
    
        //using unordered set
        
        /*
        if(root==NULL) return false;
        if(ust.count(k-root->val)) return true;    
        
        ust.insert(root->val);
           
        return (findTarget(root->left, k) or findTarget(root->right, k));
        */
        
        ///Approach-02: using inorder traversal + two pointer
        
        if(root==NULL) return false;
        vector<int> values;
        
        stack<TreeNode*> stk;
        while(root!=NULL or !stk.empty()){
            
            while(root!=NULL){
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();
            
            values.push_back(root->val);
            
            root = root->right;
        }
        
        for(auto& i: values){
            cout<<i<<" ";
        }
        
        ///now search in values if there is two number in values array
        return ifExists(values, k);
    }
private:
    bool ifExists(vector<int> &values, int k){
        int left = 0, right = values.size()-1;
        
        while(left<right){
            int sum = values[left]+values[right];
            if(sum==k) return true;
            else if(sum<k) left++;
            else right--;
        }
        
        return false;
    }
};
