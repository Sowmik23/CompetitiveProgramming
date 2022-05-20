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
    vector<int> nums ;
    TreeNode* global = NULL;
    
    void recoverTree(TreeNode* root) {
        
        
        //working solution
        //Time: O(N)
        //Space: O(N)
        /*
        inorderTraversal(root, nums);
        
        sort(nums.begin(), nums.end());
    
        inorderRebuildTree(root, nums);
        */
        
        //recursive solution
        
        TreeNode* curr = root;
        leftSubtree(curr, curr);
        
        TreeNode* tmp = new TreeNode();
        
        cout<<"left side: "<<global->val<<endl;
        tmp->val = root->val;
        root->val = global->val;
        global->val = tmp->val; 
    }
private:
    void leftSubtree(TreeNode* root, TreeNode* child){
        
        if(!child) return;
        
        leftSubtree(child, child->left);
        if(child->val<root->val){
            global = child;
            return;
        }
        leftSubtree(child, child->right);
    }
    
    TreeNode* rightSubtree(TreeNode* root, TreeNode* child){   
        if(!child) return NULL;
        
        if(child->val<root->val) return child;

        rightSubtree(root, child->right);

        rightSubtree(root, child->left);
        
        return NULL;
    }
    
    
    void inorderTraversal(TreeNode* root, vector<int> &nums){
        if(!root) return;
        inorderTraversal(root->left, nums);
        nums.push_back(root->val);
        inorderTraversal(root->right, nums);
    }
    
    void buildTree(TreeNode* root, vector<int> &nums, int left, int right){
        if(left<right){
            int mid = (left+right)/2;
            root = new TreeNode(nums[mid]);
            ///root->left = buildTree(root, nums, left, mid-1);
           /// root->right = buildTree(root, nums, mid+1, right);   
        }
    }
    
    int j = 0;
    void inorderRebuildTree(TreeNode* root, vector<int> &nums){
        if(!root) return;
        
        inorderRebuildTree(root->left, nums);
        root->val = nums[j];
        j++;
        inorderRebuildTree(root->right, nums);
    }
};
