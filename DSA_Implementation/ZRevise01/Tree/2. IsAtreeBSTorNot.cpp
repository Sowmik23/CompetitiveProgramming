#include <bits/stdc++.h>
using namespace std;

// Another approach could be storing the inorder traversal of BT 
// in a temp array and check if the array is sorted in increasing order.
// If yes, then its a BST.

struct Node {
	int val;
	Node* next;
}

bool IsBstUtil(Node* root, int minValue, int maxValue){
	if(root==NULL) return true;
	
	if(root->val < minValue and root->val > maxValue 
		and IsUtil(root->left, minValue, root->val) 
		and IsUtil(root->right, root->val, maxValue)){
			return true;
	}
	else return false;
}


bool IsBinarySearchTree(Node* root){
	return IsBstUtil(root, INT_MIN, INT_MAX);
}


int main(){
	
	
	return 0;
}
