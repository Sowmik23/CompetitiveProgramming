#include <bits/stdc++.h>
using namespace std;


//recursive version

void inorderTraversal(Node* root){
	if(root==NULL) return;
	
	inorderTraversal(root->left);
	
	cout<<root->val<<" ";
	
	inorderTraversal(root->right);
}

//iterative version
void inorderTraversalIterative(Node* root){
	
	stack<Node*> stk;
	Node* curr = root;
	
	while(curr!=NULL or !stk.empty()){
		
		while(curr!=NULL){
			stk.push(curr);
			curr = curr->left;
		}
		curr = stk.top();
		stk.pop();
		
		cout<<curr->val<<" ";
		
		curr = curr->right;
	}
}


int main(){
	
	
	
	return 0;
}
