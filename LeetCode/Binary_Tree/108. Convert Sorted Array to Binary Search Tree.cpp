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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return bstUtill(nums, 0, nums.size()-1);
    }

private:
    TreeNode* bstUtill(vector<int> &nums, int l, int r){

        if(l>r) return NULL;

        int mid = l+(r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = bstUtill(nums, l, mid-1);
        root->right = bstUtill(nums, mid+1, r);

        return root;
    }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return buildTree(nums, 0, nums.size()-1);
    }
private:
    TreeNode* buildTree(vector<int> &nums, int left, int right){
        if(left>right) return NULL;

        int mid = left+(right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, left, mid-1);
        root->right = buildTree(nums, mid+1, right);

        return root;
    }
};
