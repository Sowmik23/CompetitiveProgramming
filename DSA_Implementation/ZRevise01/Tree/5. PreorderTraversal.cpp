#include <bits/stdc++.h>
using namespace std;


//recursive version
void preorderTraversal(Node* root){
	if(root==NULL) return;
	
	cout<<root->val<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}


//iterative version
void preorderTraversalIterative(Node* root){
	
	if(root==NULL) return;
	
	stack<Node*> stk;
	stk.push(root);
	
	Node* curr = root;
	
	while(!stk.empty()){
		
		if(curr!=NULL){
			cout<<curr->val<<" ";
			if(curr->right!=NULL){
				stk.push(curr->right);
			}
			curr = curr->left;
		}
		else
		{
			curr = curr.top();
			stk.pop();
		}
	}
}


int main(){
	
	
	return 0;
}
