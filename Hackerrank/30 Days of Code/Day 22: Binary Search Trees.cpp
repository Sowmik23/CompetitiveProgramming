#include<bits/stdc++.h>
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


class Tree {
	public:
		Node *insert(Node* root, int data){
			if(root==NULL) {
				return new Node(data);
			}
			else {
				Node* tmp;
				if(data <= root->data){
					tmp = insert(root->left, data);
					root->left = tmp;
				}
				else {
					tmp = insert(root->right, data);
					root->right = tmp;
				}
				return root;
			}
		}
		
		int getHeight(Node* root) {
			if(root==NULL) return -1;
			
			int leftDepth = getHeight(root->left);
			int rightDepth = getHeight(root->right);
			
			return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
		}
};


int main(){
	
	int n;
	cin>>n;
	Node* root = NULL;
	Tree myTree;
	
	while(n--){
		int data;
		cin>>data;
		root = myTree.insert(root, data);
	}
	
	cout<<myTree.getHeight(root)<<endl;
	
	return 0;
}
