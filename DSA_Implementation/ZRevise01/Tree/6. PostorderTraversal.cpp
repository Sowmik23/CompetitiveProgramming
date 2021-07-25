#include <bits/stdc++.h>
using namespace std;

//recursive version
void postorderTraversal(Node* root){
	
	if(root==NULL) return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->val<<" ";
}


//iterative version
void postorderTraversalIterative(Node* root){
	
	stack<Node*> stk;
	stack<int> res;
	stk.push(root);
	
	while(!stk.empty()){
		Node* curr = stk.top();
		stk.pop();
		res.push(curr->val);
		
		if(curr->left!=NULL){
			stk.push(curr->left);
		}
		if(curr->right!=NULL){
			stk.push(curr->right);
		}
	}
	
	while(!res.empty()){
		cout<<res.top()<<" ";
		res.pop();
	}
	cout<<endl;
}



int main(){
	
	
	
	return 0;
}
