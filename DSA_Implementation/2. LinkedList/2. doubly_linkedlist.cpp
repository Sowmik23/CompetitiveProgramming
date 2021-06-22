#include <bits/stdc++.h>
using namespace std;

/*
 * insertFirst(): O(1)
 * insertLast(): O(1)
 * insertAfter(): O(1)
 * 
 * deleteFirst(): O(1)
 * deleteLast(): O(1)
 * 
 * search():
 * print():
 */


struct Node{
	int val;
	Node* next;
	Node* prev;
};


class DoublyLinkedList{
	Node* head = NULL;
	Node* last = NULL;
	int Size = 0;
	
	public:
	void insertFirst(int val){ //O(1)
		Node* tmp = new Node;
		tmp->val = val;
		tmp->prev = NULL;
		
		if(head==NULL) {
			head = last = tmp;
		}
		else {
			tmp->next = head;
			head->prev = tmp;
			head = tmp;
		}
		Size++;
	}
	
	void insertLast(int val){ //O(1)
		Node* tmp = new Node;
		tmp->val = val;
		tmp->next = NULL;
		
		if(last==NULL){
			head = last = tmp;
		}
		else {
			tmp->prev = last;
			last->next = tmp;
			last = tmp;
		}
		Size++;
	}
	
	void insertAfterNode(int val){ //O(1)
		//this line is for testing 
		Node* prev_node = head->next;
		
		if(prev_node ==NULL){
			cout<<"Previous Node can't be null"<<endl;
			return ;
		}
		Node* tmp = new Node;
		tmp->val = val;
		tmp->next = prev_node->next;
		prev_node->next = tmp;
		
		tmp->prev = prev_node;
		
		
		if(tmp->next!=NULL){
			tmp->next->prev = tmp;
		}
		Size++;
	}
	
	void deleteFirst(){ //O(1)
		if(head==NULL){
			cout<<"Empty"<<endl;
			return ;
		}
		if(head==last){
			head = last = NULL;
		}
		else {
			head = head->next;
			head->prev = NULL;
		}
		Size--;
	}
	
	void deleteLast(){ //O(1)
		if(last==NULL){
			cout<<"Empty"<<endl;
			return ;
		}
		if(head == last){
			head = last = NULL;
		}
		else {
			last = last->prev;
			last->next = NULL;
		}
		Size--;
	}
		
	int size(){ //O(1)
		return Size;
	}
	
	void print(){ //O(n)
		Node* tmp;
		tmp = head;
		while(tmp!=NULL){
			cout<<tmp->val<<" ";
			tmp = tmp->next;
		}
		cout<<endl;
	}
};


int main(){
	
	DoublyLinkedList dll;
	
	dll.insertFirst(1);
	dll.insertFirst(2);
	dll.insertFirst(3);
	dll.insertFirst(4);
	dll.insertFirst(5);
	
	dll.print();
	
	dll.insertLast(6);
	dll.insertLast(7);
	dll.insertLast(8);
	
	dll.print();
	
	
	dll.insertAfterNode(10);
	dll.print();
	
	return 0;
}
