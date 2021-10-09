#include <bits/stdc++.h>
using namespace std;


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


//preorder recursive
vector<int> preOrderRecursive(TreeNode* root, vector<int> &res){
	if(root==NULL) return {};
	
	res.push_back(root->val);
	preOrderRecursive(root->left, res);
	preOrderRecursive(root->right, res);
	
	return res;
}

//preorder iterative
vector<int> preOrderIterative(TreeNode* root){
	
	if(root==NULL) return {};
	vector<int> res;
	stack<TreeNode*> stk;
	
	stk.push(root);
	TreeNode* curr= root;
	
	while(!stk.empty()){
		if(curr!=NULL){
			res.push_back(curr->val);
			
			if(curr->right!=NULL) stk.push(curr->right);
			curr = curr->left;
		}
		else {
			curr = stk.top();
			stk.pop();
		}
	}
	
	return res;
}


//inorder recursive
vector<int> inorderRecursive(TreeNode* root, vector<int> &res){
	
	if(root==NULL) return {};
	
	inorderRecursive(root->left, res);
	res.push_back(root->val);
	inorderRecursive(root->right, res);
	
	return res;
}

//inorder iterative
vector<int> inorderIterative(TreeNode* root){
	
	if(root==NULL) return {};
	vector<int> res;
	stack<TreeNode*> stk;
	TreeNode* curr = root;
	
	while(!stk.empty() or curr!=NULL){
		while(curr!=NULL){
			stk.push(curr);
			curr = curr->left;
		}
		curr = stk.top();
		stk.pop();
		
		res.push_back(curr->val);
		curr = curr->right;
	}
	
	return res;
}


//postorder recursive
vector<int> postorderRecursive(TreeNode* root, vector<int> & res){
	
	if(root==NULL) return {};
	postorderRecursive(root->left, res);
	postorderRecursive(root->right, res);
	
	res.push_back(root->val);
	
	return res;
}


//postorder iterative
vector<int> postorderIterative(TreeNode* root){
	if(root==NULL) return {};
	
	vector<int> res;
	stack<TreeNode*> stk;
	TreeNode* curr = root;
	stk.push(root);
	
	while(!stk.empty()){
		curr = stk.top();
		stk.pop();
		
		res.push_back(curr->val);
		
		if(curr->left!=NULL) stk.push(curr->left);
		if(curr->right!=NULL) stk.push(curr->right);
	}
	
	reverse(res.begin(), res.end());
	
	return res;
}


//Level Order Traversal
vector<vector<int>> levelOrderTraversal(TreeNode* root){
	
	if(root==NULL) return {};
	
	vector<vector<int>> res;
	vector<int> tmp;
	queue<TreeNode*> q;
	
	q.push(root);
	
	while(!q.empty()){
		int n =q.size();
		for(int i=0;i<n;i++){
			TreeNode* top = q.front();
			q.pop();
			
			tmp.push_back(top->val);
			if(top->left!=NULL) q.push(top->left);
			if(top->right!=NULL) q.push(top->right);
		}
		res.push_back(tmp);
		tmp = vector<int> ();
	}
	
	return res;
}
	


int main(){
	
	
	
	return 0;
}
