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


class BinarySearchTree{
	private:
		TreeNode* root = NULL;
		
	public:
		void insert(int val){
			if(root==NULL){
				root = new TreeNode(val);
			}
			else {
				TreeNode* curr = root;
				TreeNode* parent;
				while(curr!=NULL){
					parent = curr;
					if(val<curr->val){
						curr = curr->left;
					}
					else if(val>curr->val) {
						curr = curr->right;
					}
					else {
						cout<<"Value already exists"<<endl;
						return ;
					}
				}
				if(val<parent->val){
					parent->left = new TreeNode(val);
				}
				else {
					parent->right = new TreeNode(val);
				}
			}
		}
		
		bool search(int val){
			TreeNode* curr = root;
			while(curr!=NULL){
				if(curr->val==val) return true;
				if(curr->val<val) curr = curr->right;
				else if(curr->val>val) curr = curr->left;
			}
			return false;
		}
		
		bool deleteNode(int val){
			TreeNode* curr = root;
			TreeNode* parent = root;
			
			while(curr->val!=val){
				parent = curr;
				if(curr->val<val) curr = curr->right;
				else if(curr->val>val) curr = curr->left;
				if(curr==NULL) return false;
			}
			
			//case-01: child node
			if(curr->left==NULL and curr->right==NULL){
				if(curr==root){
					root = NULL;
				}
				else if(parent->val>val){
					parent->left = NULL;
				}
				else {
					parent->right = NULL;
				}
				
				delete(curr);
				return true;
			}
			
			//case-02: curr have one(left) child
			if(curr->right==NULL){
				if(curr==root){
					root->left = curr->left;
				}
				else {
					if(parent->val<val){
						parent->right = curr->left;
					}
					else parent->left = curr->left;
				}
				delete(curr);
				return true;
			}
			
			else if(curr->left==NULL){
				if(root==curr){
					root->right = curr->right;
				}
				else {
					if(parent->val<val) parent->right = curr->right;
					else parent->left = curr->right;
				}
				delete(curr);
				return true;
			}
			
			//case-03: curr has both child
			if(curr->left!=NULL and curr->right!=NULL){
				TreeNode* successor = getBiggestNodeFromLeftSubtree(curr);
				
				successor->left = curr->left;
				successor->right = curr->right;
				
				if(curr==root){
					root = successor;
				}
				else if(parent->val<val) parent->right = successor;
				else parent->left = successor;
				
				delete(curr);
				return true;
			}
			
			return false;
		}
		
		TreeNode* getBiggestNodeFromLeftSubtree(TreeNode* curr){
			TreeNode* parent = curr->left;
			TreeNode* rightChild = parent->right;
			
			if(rightChild==NULL){
				curr->left = parent->left;
				return parent;
			}
			while(rightChild->right!=NULL){
				parent = rightChild;
				rightChild = rightChild->right;
			}
			
			parent->right = rightChild->left;
			return rightChild;
		}
		
		void printBST(){
			printBST("", this->root, false);
		}
		void printBST(const string& prefix, const TreeNode* node, bool isLeft){
			if(node!=NULL){
				cout<<prefix;
				
				cout<<(isLeft ? "|---" : "|___");
				
				cout<<node->val<<endl;
				
				printBST(prefix+(isLeft ? "|   " : "     "), node->left, true);
				printBST(prefix+(isLeft ? "|   " : "     "), node->right, false);
			}
		}
			
	};
		


int main(){
	
	BinarySearchTree bt;
	
	bt.insert(1);
	bt.insert(5);
	bt.insert(2);
	bt.insert(44);
	bt.insert(23);
	bt.insert(3);
	
	bt.printBST();
	
	
	bt.deleteNode(44);
	
	bt.printBST();
	
	bt.deleteNode(5);
	bt.printBST();
	
	
	return 0;
}
