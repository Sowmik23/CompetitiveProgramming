#include <bits/stdc++.h>
using namespace std;


int minDepth(Node* root){
	if(root==NULL) return 0;
	if(root->left==NULL){
		return 1+minDepth(root->right);
	}
	if(root->right==NULL){
		return 1 + minDepth(root->left);
	}
	
	return 1 + min(minDepth(root->left), minDepth(root->right));
}

int maxDepth(Node* root){
	if(root==NULL) return 0;
	if(root->left==NULL){
		return 1+maxDepth(root->right);
	}
	if(root->right==NULL){
		return 1 + maxDepth(root->left);
	}
	
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}


int main(){
	
	
	
	
	return 0;
}
