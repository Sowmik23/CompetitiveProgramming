#include <bits/stdc++.h>
using namespace std;


struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

class BST{
	public:
		Node* insert(Node* root, int data){
			if(root==NULL) return new Node(data);
			else {
				Node* tmp;
				if(data< root->data){
					tmp = insert(root->left, data);
					root->left = tmp;
				}
				else if(data> root->data){
					tmp = insert(root->right, data);
					root->right = tmp;
				}
				
				return root;
			}
		}
		
		void levelOrderTraversal(Node* root){
			queue<Node* > q;
			Node* tmp = root;
			
			while(tmp!=NULL){
				cout<<tmp->data<<" ";
				
				if(tmp->left != NULL) q.push(tmp->left);
				if(tmp->right != NULL) q.push(tmp->right);
				
				if(!q.empty()){
					tmp = q.front();
					q.pop();
				}
				else {
					tmp = NULL;
				}
			}
		}
};

int main(){
	
	int n;
	cin>>n;
	int data;
	
	BST myBST;
	Node* root = NULL;
	while(n--){
		cin>>data;
		root = myBST.insert(root, data);
	}
	myBST.levelOrderTraversal(root);
	
	
	return 0;
}
