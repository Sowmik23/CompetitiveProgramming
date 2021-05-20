#include <bits/stdc++.h>
using namespace std;

/*
 * Level Order Traversal
 * Time: O(n), Memory: O(n)
 */



struct Node{
	int val;
	Node* left;
	Node* right;
	
	Node(int value){
		val = value;
		left = NULL;
		right = NULL;
	}
};


void level_order(Node* root){
	if(root==NULL) return;
	queue<Node*> q;
	
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		Node* top = q.front();
		q.pop();
		//cout<<top->val<<"kdfk"<<endl; break;
		///condition to check occurrence of next level
		if(top==NULL){
			q.push(NULL);
			cout<<endl;
		}
		else {
			if(top->left!=NULL) q.push(top->left);
			if(top->right!=NULL) q.push(top->right);
			
			cout<<top->val<<" ";
		}
	}
}


int main(){
	
	///Insert element into the tree
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
	level_order(root);
	
	
	return 0;
}
