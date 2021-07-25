#include <bits/stdc++.h>
using namespace std;


struct Node {
	int val;
	Node* left;
	Node* right;
	
	Node(int value){
		this->val = value;
		this->left = NULL;
		this->right = NULL;
	}
	
	void setValue(int value){
		this->val = value;
	}
	
	void setLeft(Node* left){
		this->left = left;
	}
	
	void setRight(Node* right){
		this->right = right;
	}
	
	int getValue(){
		return val;
	}
	
	Node* getLeft(){
		return left;
	}
	
	Node* getRight(){
		return right;
	}
};
	

class BinarySearchTree {
	Node* root = NULL;
	
public: 
	void insert(int data){  //insert: O(log n)
		if(root==NULL){
			root = new Node(data);
			return ;
		}
		
		Node* parent = root;
		Node* curr = root;
		while(curr!=NULL){
			parent = curr;
			if(curr->getValue() < data){
				curr = curr->getRight();
			}
			else if(curr->getValue() > data){
				curr = curr->getLeft();
			}
			else { //the value is already in the tree
				return ;
			}
		}
		if(parent->getValue() < data){
			parent->setRight(new Node(data));
		}
		else {
			parent->setLeft(new Node(data));
		}
	}
	
	bool Search(int data){ //search: O(log n)
		if(root==NULL){
			return false;
		}
		Node* curr = root;
		while(curr!=NULL){
			if(curr->getValue()==data) return true;
			else if(curr->getValue()<data) {
				curr = curr->getRight();
			}
			else if(curr->getValue() > data){
				curr = curr->getLeft();
			}
		}
		return false;
	}
	
	bool deleteValue(int data){
		
		if(root==NULL) return false; //in case of tree is empty
		
		Node* parent = root;
		Node* curr = root;
		while(curr->getValue()!=data){
			parent = curr;
			if(curr->getValue() < data){
				curr = curr->getRight();
			}
			else if(curr->getValue() > data){
				curr = curr->getLeft();
			}
			if(curr==NULL) return false;
		}
		///In case of deletion of curr we have 03 case
		//case-01: current is a leaf
		//case-02: current have one child
		//case-03: current have left and right child
		
		//case-01:current is a leaf
		if(curr->getLeft()==NULL and curr->getRight()==NULL){
			if(curr==root){
				root = NULL;
			}
			else if(parent->getValue() < data){
				parent->setRight(NULL);
			}
			else if(parent->getValue() > data){
				parent->setLeft(NULL);
			}
			return true;
		}
		
		//case-02: current have one child
		if(curr->getLeft()==NULL){
			if(curr==root){
				root = curr->getRight();
			}
			else if(parent->getValue() < data){
				parent->setRight(curr->getRight());
			}
			else if(parent->getValue() > data){
				parent->setLeft(curr->getRight());
			}
			return true;
		}
		else if(curr->getRight()==NULL){
			if(root==NULL){
				root = curr->getLeft();
			}
			else if(parent->getValue() < data){
				parent->setRight(curr->getLeft());
			}
			else if(parent->getValue() > data){
				parent->setLeft(curr->getLeft());
			}
			return true;
		}
		
		//case-03: if current have both left and right child
		if(curr->getLeft()!=NULL and curr->getRight()!=NULL){
			
			Node* successor = getBiggestNodeFromLeftSubtree(curr);
		
			successor->setLeft(curr->getLeft());
			successor->setRight(curr->getRight());
			
			if(curr==root){
				root = successor;
			}
			else if(parent->getValue() < data){
				parent->setRight(successor);
			}
			else {
				parent->setLeft(successor);
			}
			return true;
		}
		return false;
	}
	
	void inOrderPrint(){ //iterative inorder traversal
		Node* curr = root;
		stack<Node*> stk;
		
		while(curr!=NULL or !stk.empty()){
			while(curr!=NULL){
				stk.push(curr);
				curr = curr->left;
			}
			curr = stk.top();
			stk.pop();
			cout<<curr->getValue()<<" ";
			
			curr = curr->getRight();
		}
		cout<<endl;
	}
	
	
private:
	Node* getBiggestNodeFromLeftSubtree(Node* curr){
		
		Node* parent = curr->getLeft();
		Node* rightChild = parent->getRight();
		
		if(rightChild==NULL){
			curr->setLeft(parent->getLeft());
			return parent;
		}
		while(rightChild->getRight()!=NULL){
			parent = rightChild;
			rightChild = rightChild->getRight();
		}
		
		//the most rightchild is the biggest node
		//now, if right child have any left child it will also works
		//and it will be set right child of parent
		//if the left child is null, it will also works as right child 
		//of parent will also null
		parent->setRight(rightChild->getLeft());
		
		return rightChild;
	}	
};


int main(){
	
	BinarySearchTree bst;
	
	bst.insert(2);
	bst.insert(10);
	bst.insert(3);
	bst.insert(14);
	bst.insert(5);
	bst.insert(9);
	
	bst.inOrderPrint();
	
	
	return 0;
}
