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
        
        
        //Approach-01: using map + recursion: Time: O(n), Space: O(n)
        /*
        unordered_map<int, int> mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        int rootIndex =0, left = 0, right = inorder.size()-1;
        
        return splitTree(preorder, inorder, mp, rootIndex, left, right);
        */
        
        ///Approach-02: without using map: Time: O(n*n), Space: O(1): 
        
        return HelperWithoutMap(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);;
    }
    
private:
    TreeNode* splitTree(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &mp, int rootIndex, int left, int right){
        
        int root_val = preorder[rootIndex];
        int root_index = mp[root_val];
        
        TreeNode* root_node = new TreeNode(root_val);
        
        if(root_index>left){
            root_node->left = splitTree(preorder, inorder, mp, rootIndex+1, left, root_index-1);
        }
        if(root_index<right) {
            root_node->right = splitTree(preorder, inorder, mp, rootIndex+root_index-left+1, root_index+1, right);
        }
        
        return root_node;
    }
    
    //approach-02:
    TreeNode* HelperWithoutMap(vector<int> &preorder, vector<int>&inorder, int preStart, int preEnd, int inStart, int inEnd){
        if(inStart>inEnd) return NULL;
        
        int root_val = preorder[preStart];
        
        TreeNode* root = new TreeNode(root_val);
        
        int root_index;
        for(int i=inStart;i<inEnd;i++){
            if(inorder[i]==root_val) {
                root_index = i;
                break;
            }
        }
        
        root->left = HelperWithoutMap(preorder, inorder, preStart+1, preStart+root_index-inStart, inStart, root_index-1);
        root->right = HelperWithoutMap(preorder, inorder, preStart+root_index-inStart+1, preEnd, root_index+1, inEnd);
        
        return root;
    }
};
