#include <bits/stdc++.h>
using namespace std;

/*
 * Doubly Linked List:
 * 
 * insertFirst(): O(1)
 * insertLast(): O(1)
 * deleteFirst(): O(1)
 * deleteLast(): O(1)
 * Size(): O(1)
 * print(): O(n)
 */



#define private public

struct Node {
	int val;
	Node* next;
	Node* prev;
};


class DoublyLinkedList{
	Node* root = NULL;
	Node* tail = NULL;
	int Size = 0;
	
private:
	void insertFirst(int data){ //O(1)
		Node* tmp = new Node;
		tmp->val = data;
		tmp->prev = NULL;
		
		if(root==NULL) root = tail = tmp;
		else {
			tmp->next = root;
			root->prev = tmp;
			root = tmp;
		}
		Size++;
	}
	
	void insertLast(int data){ //O(1)
		Node* tmp = new Node;
		tmp->val = data;
		tmp->next = NULL;
		
		if(root==NULL) root = tail = tmp;
		else {
			tail->next = tmp;
			tmp->prev = tail;
			tail = tmp;
		}
		Size++;
	}
	
	void deleteFirst(){ //O(1)
		if(root==NULL){
			cout<<"List is empty!"<<endl;
			return;
		}
		int data = root->val;
		if(root==tail) {
			root = tail = NULL;
		}
		else root = root->next;
		cout<<data<<" is deleted!"<<endl;
	}
	
	void deleteLast(){ //O(1)
		if(root==NULL) {
			cout<<"List is empty()!"<<endl;
			return;
		}
		int data = tail->val;
		if(root==tail){
			root = tail = NULL;
		}
		else {
			tail = tail->prev;
			tail->next = NULL;
		}
		cout<<data<<" is deleted"<<endl;
	}
	
	int size(){ //O(1)
		return Size;
	}
	
	void print(){ //O((n)
		Node* curr = root;
		while(curr!=NULL){
			cout<<curr->val<<" ";
			curr = curr->next;
		}
		cout<<endl;
	}
};


int main(){
	
	DoublyLinkedList dll;
	
	dll.insertFirst(1);
	dll.insertFirst(2);
	dll.insertFirst(3);
	
	dll.print();
	cout<<"List size is: "<<dll.size()<<endl;
	
	dll.insertLast(4);
	dll.insertLast(5);
	dll.insertLast(6);
	
	dll.print();
	
	dll.deleteFirst();
	
	dll.print();
	
	dll.deleteLast();
	
	dll.print();
	
	
	return 0;
}
