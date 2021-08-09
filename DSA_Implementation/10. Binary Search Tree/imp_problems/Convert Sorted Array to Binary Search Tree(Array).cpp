#include <bits/stdc++.h>
using namespace std;


///Convert a sorted array into balanced BST
// Time: O(n)

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	
	TreeNode(int val){
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode* bstUtil(vector<int> &nums, int l, int r){
	if(l>r) return NULL;
	
	int mid = (l+r)/2;
	TreeNode* root = new TreeNode(nums[mid]);
	
	root->left = bstUtil(nums, l, mid-1);
	root->right = bstUtil(nums, mid+1, r);

	return root;
}

void testInorder(TreeNode* root){
	
	stack<TreeNode*> stk;
	
	while(root!=NULL or !stk.empty()){
		while(root!=NULL){
			stk.push(root);
			root = root->left;
		}
		
		root = stk.top();
		cout<<root->val<<" ";
		stk.pop();
		
		root = root->right;
	}
}

TreeNode* sortedArrayToBST(vector<int> &nums){
	
	return bstUtil(nums, 0, nums.size()-1);
}



int main(){
	
	vector<int> nums = { -10, -2, 0, 1, 4, 9, 123};
	
	TreeNode* r = sortedArrayToBST(nums);
	
	testInorder(r);
	
	return 0;
}
