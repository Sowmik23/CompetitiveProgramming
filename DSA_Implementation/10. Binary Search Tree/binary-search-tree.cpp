#include <bits/stdc++.h>
using namespace std;


class BinarySearchTreeNode {
	int val;
	BinarySearchTreeNode *left;
	BinarySearchTreeNode *right;
	
	public:
	BinarySearchTreeNode(int val){
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
	
	void setValue(int value){
		val = value;
	}
	void setRight(BinarySearchTreeNode* right){
		this->right = right;
	}
	void setLeft(BinarySearchTreeNode* left){
		this->left = left;
	}
	
	int getValue(){
		return val;
	}
	BinarySearchTreeNode* getRight(){
		return right;
	}
	BinarySearchTreeNode* getLeft(){
		return left;
	}
};

class BinarySearchTree {
	BinarySearchTreeNode *root;
	
	public:
	BinarySearchTree(){
		root = nullptr;
	}
	
	//insertion
	void insert(int value){
		if(root==nullptr) {
			root = new BinarySearchTreeNode(value);
			return;
		}
		BinarySearchTreeNode *parent = root;
		BinarySearchTreeNode *current = root;
		while(current!=nullptr){
			parent = current;
			if(current->getValue() < value){
				current = current->getRight();
			}
			else if(current->getValue() > value){
				current = current->getLeft();
			}
			else {  //the value is already in the tree
				return ;
			}
		}
		if(parent->getValue() <value) {
			parent->setRight(new BinarySearchTreeNode(value));
		}
		else parent->setLeft(new BinarySearchTreeNode(value));
	}
	
	//search
	bool search(int value){
		BinarySearchTreeNode *current = this->root;
		while(current!=nullptr){
			if(current->getValue() < value) {
				current = current->getRight();
			}
			else if(current->getValue()> value){
				current = current->getLeft();
			}
			else {
				return true;
			}
		}
		return false;
	}
	
	//delete value from tree
	bool deleteValue(int value){
		
		if(this->root==nullptr) return false; //if tree is empty
		
		BinarySearchTreeNode *current = this->root;
		BinarySearchTreeNode *parent = nullptr;
		
		while(current->getValue() !=value){
			parent = current;
			if(current->getValue() < value){
				current = current->getRight();
			}
			else if(current->getValue() > value){
				current = current->getLeft();
			}
			
			if(current==nullptr){
				return false; //value is not present in the tree
			}
		}
		
		//now we need to delete current node and we have 3 cases:
		///Case: 01 - current is a leaf
		if((current->getLeft()==nullptr) and (current->getRight()==nullptr)){
			if(current == this->root){
				this->root = nullptr;
			}
			else if(parent->getValue() < current->getValue()){
				parent->setRight(nullptr);
			}
			else {
				parent->setLeft(nullptr);
			}
			return true;
		}
		///Case: 02 - current have one child
		if(current->getLeft()==nullptr){
			if(current==this->root){
				this->root = current->getRight();
			}
			else if(parent->getValue() < current->getValue()){
				parent->setRight(current->getRight());
			}
			else {
				parent->setLeft(current->getRight());
			}
			return true;
		}
		else if(current->getRight()==nullptr){
			if(current==this->root){
				this->root = current->getLeft();
			}
			else if(parent->getValue() < current->getValue()){
				parent->setRight(current->getLeft());
			}
			else {
				parent->setLeft(current->getLeft());
			}
			return true;
		}
		///Case: 03 - current have left and right child
		if((current->getLeft()!=nullptr) and (current->getRight()!=nullptr)){
			BinarySearchTreeNode *successor = getBiggestNodeFromLeftSubtree(current);
			
			successor->setLeft(current->getLeft());
			successor->setRight(current->getRight());
			
			if(current==this->root){
				this->root = successor;
			}
			else if(parent->getValue() < current->getValue()){
				parent->setRight(successor);
			}
			else {
				parent->setLeft(successor);
			}
			return true;
		}
		return false;
	}
	
	void print(){
		int length = 1;
		BinarySearchTreeNode** nodes = new BinarySearchTreeNode*[length];
		nodes[0] = this->root;
		
		if(this->root==nullptr) return;
		
		int height = max(getHeight(this->root->getLeft()), getHeight(this->root->getRight()));
		
		while(haveNodesToPrint(nodes, length)){
			int offset = (int) pow(2, height+1);
			for(int i=0;i<length;i++){
				printSpace(offset); //offset before every number
				if(nodes[i]!=nullptr){
					cout<<nodes[i]->getValue();
				}
				else {
					cout<<" ";
				}
				printSpace(offset-2); //because we expect the number to have lenght of 2
			}
			///print the spaces
			for(int i=0;i<=height;i++){
				cout<<endl;
			}
			
			///prepare for printing next line
			BinarySearchTreeNode** newNodes = new BinarySearchTreeNode*[length*2]; //every node has 2 childs
			
			int idx = 0;
			for(int j=0;j<length;j++){
				if(nodes[j]!=nullptr){
					newNodes[idx] = nodes[j]->getLeft();
					idx++;
					newNodes[idx] = nodes[j]->getRight();
					idx++;
				}
				else //even if it is nullptr you need to print spaces
				newNodes[idx] = nullptr;
				idx++;
				newNodes[idx] = nullptr;
				idx++;
			}
			length = length*2;
			nodes = newNodes;
			height--;
		}
	}
	
	void printSortedOrder(){ //inorder traversal without recursion
		BinarySearchTreeNode* current = this->root;
		BinarySearchTreeNode* parent;
		
		while(current!=nullptr){
			if(current->getLeft()==nullptr){
				cout<<current->getValue()<<" ";
				current = current->getRight();
			}
			else {
				parent = current->getLeft();
				while((parent->getRight()!=nullptr) and (parent->getRight()!=current)){
					parent = parent->getRight();
				}
				
				if(parent->getRight()==nullptr){
					parent->setRight(current);
					current = current->getLeft();
				}
				else {
					parent->setRight(nullptr);
					cout<<current->getValue()<<" ";
					current = current->getRight();
				}
			}
		}	
	}
	
	private:
	int getHeight(BinarySearchTreeNode* current){
		if(current==nullptr) return 0;
		return 1+ max(getHeight(current->getRight()), getHeight(current->getLeft()));
	}
	
	bool haveNodesToPrint(BinarySearchTreeNode** nodes, int n){
		for(int i=0;i<n;i++){
			if(nodes[i]!=nullptr){
				return true;
			}
		}
		return false;
	}
	
	void printSpace(int n){
		while(n!=0){
			cout<<" ";
			n--;
		}
	}
	
	BinarySearchTreeNode* getBiggestNodeFromLeftSubtree(BinarySearchTreeNode* current){
		
		BinarySearchTreeNode *parent = current->getLeft();
		BinarySearchTreeNode *rightChild = parent->getRight();
		
		if(rightChild==nullptr){  //if left subtree have no right child
			current->setLeft(parent->getLeft());
			return parent;
		}
		
		while(rightChild->getRight()!=nullptr){
			parent = rightChild;
			rightChild = rightChild->getRight();
		}
		
		///the most right rightChild is the biggest node
		///Now, if right child have any left child it will be set right child of parent
		///if the left child is null, it will also works as right child of parent will also null
		parent->setRight(rightChild->getLeft());
		
		return rightChild;
	}
};


int main(){
	
	BinarySearchTree BST;
	
	BST.insert(2);
	BST.insert(10);
	BST.insert(3);
	BST.insert(14);
	BST.insert(5);
	BST.insert(9);
	
	BST.printSortedOrder();
	//BST.print();
	
	bool k = BST.search(9);
	if(k==true) cout<<"found"<<endl;
	else cout<<"Not found"<<endl;
	
	bool d = BST.deleteValue(10);
	if(d==true) cout<<"Value deleted successfully"<<endl;
	else cout<<"Value not found"<<endl;
	
	
	return 0;
}
