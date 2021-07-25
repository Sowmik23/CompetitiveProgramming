#include <bits/stdc++.h>
using namespace std;


struct Node {
	int val;
	Node* next;
	
	Node(Node* root, int data){
		this->next = root;
		this->val = data;
	}
};


class LinkedList {
	Node* root = NULL;
	
public:
	void insertToLinkedList(int data){
		
		this->root = new Node(root, data);
	}
	
	bool searchList(int data){
		Node* curr = root;
		while(curr!=NULL){
			if(curr->val == data) return true;
			curr = curr->next;
		}
		return false;
	}
	
	bool deleteVal(int data){
		if(root==NULL) return  false;
		else if(root->val==data){
			root= root->next;
			return true;
		}
		else {
			Node* curr = root;
			while(curr->next!=NULL){
				if(curr->next->val==data){
					break;
				}
				curr = curr->next;
			}
			if(curr->next==NULL) return false;
			else if(curr->next->val==data) {
				curr->next = curr->next->next;
				return true;
			}
		}
		return false;
	}
	
	void print(){
		Node* curr = root;
		while(curr!=NULL){
			cout<<curr->val<<" ";
			curr = curr->next;
		}
		cout<<endl;
	}
};


class HashTable{
	LinkedList** data;
	int length;
	
public:
	HashTable(int n){
		this->length = n;
		this->data = new LinkedList*[n];
		
		for(int i=0;i<n;i++){
			this->data[i] = new LinkedList();
		}
	}
	
	
	void insert(int value){
		///int index = abs(hashFunctionForString(value))%this->length;  //this is for string value
		int index = abs(value%this->length);
		this->data[index]->insertToLinkedList(value);
	}
	
	bool search(int value){
		int index = abs(value%this->length);
		return data[index]->searchList(value);
	}
	
	bool deleteValue(int value){
		int index = abs(value%this->length);
		return data[index]->deleteVal(value);
	}
	
	
private:
	int hashFunctionForString(string value){ ///this is for string value
		int hash = 7;
		for(int i=0;i<value.length();i++){
			hash = hash*31 + value[i];
		}
		return hash;
	}
};


int main(){
	
	/*
	//test linkedlist functions
	LinkedList lst;
	lst.insertToLinkedList(1);
	lst.insertToLinkedList(2);
	lst.insertToLinkedList(3);
	
	lst.print();
	bool k = lst.deleteVal(2);
	if(k==true) cout<<"value deleted successfully"<<endl;
	else cout<<"deletion error"<<endl;
	lst.print();
	*/
	
	HashTable ht(10);
	
	ht.insert(1);
	ht.insert(2);
	ht.insert(3);
	
	bool k = ht.search(2);
	if(k==true) cout<<"Value exists in hash table"<<endl;
	else cout<<"value not found"<<endl;
	
	k = ht.search(5);
	if(k==true) cout<<"Value exists in hash table"<<endl;
	else cout<<"value not found"<<endl;
	
	bool l = ht.deleteValue(2);
	if(l==true) cout<<"Value deleted successfully"<<endl;
	else cout<<"Deletion error"<<endl;
	
	l = ht.deleteValue(2);
	if(l==true) cout<<"Value deleted successfully"<<endl;
	else cout<<"Deletion error"<<endl;
	
	return 0;
}
