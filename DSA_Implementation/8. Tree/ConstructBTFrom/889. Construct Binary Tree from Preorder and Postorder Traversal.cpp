//Latest & easy approach:
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //Time: O(n), Space: O(n)
        
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        int preorderIndex = 0;
        int left = 0;
        int right = preorder.size()-1;
        
        return splitTree(preorder, inorder, mp, preorderIndex, left, right);
    }
private:
//***Note*** that rootIdx is passed as reference 
    TreeNode* splitTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp, int &preorderIndex, int left, int right){
        if(left>right) return NULL;
        
        int root_val = preorder[preorderIndex];
        int root_index = mp[root_val];
        TreeNode* root = new TreeNode(root_val);
        preorderIndex++;
        
      
        root->left = splitTree(preorder, inorder, mp, preorderIndex, left, root_index-1);
        
        root->right = splitTree(preorder, inorder, mp, preorderIndex, root_index+1, right);
        
        return root;
    }
};


//Another :

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
    int preIdx = 0, postIdx = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        ///approach-01: using map:
       /* unordered_map<int,int> mp;
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]] = i;
        }
        
        return splitTree(preorder, postorder, mp, 0, preorder.size()-1, 0, postorder.size()-1);
        */
        
        
        //Recursive approach:
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        
        if(root->val!=postorder[postIdx]){
            root->left = constructFromPrePost(preorder, postorder);
        }
        if(root->val!=postorder[postIdx]){
            root->right = constructFromPrePost(preorder, postorder);
        }
        postIdx++;
        
        return root;
    }
    
private:
    TreeNode* splitTree(vector<int> &preorder, vector<int> &postorder, unordered_map<int, int> &mp, int preStart, int preEnd, int postStart, int postEnd){
        if(preStart>preEnd or postStart>postEnd) return NULL;
        
        int root_val = preorder[preStart];
        TreeNode* root_node = new TreeNode(root_val);
        
        if(preStart+1<=preEnd){
            int root_index = mp[preorder[preStart+1]];
            
            root_node->left = splitTree(preorder, postorder, mp, preStart+1, preStart + root_index-postStart+1, postStart, root_index);
            
            root_node->right = splitTree(preorder, postorder, mp, preStart+1+root_index+1-postStart, preEnd, root_index+1, postEnd-1);
        }
        
        return root_node;
    } 
};
