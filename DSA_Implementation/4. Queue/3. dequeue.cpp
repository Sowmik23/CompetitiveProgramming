#include <bits/stdc++.h>
using namespace std;

/*
 * insertFirst(): O(1)
 * insertLast(): O(1)
 * deleteFirst(): O(1)
 * deleteLast(): O(1)
 * getFirst(): O(1)
 * getLast(): O(1)
 * Size(): O(1)
 * isEmpty(): O(1)
 * erase(): O(n)
 * print(): O(n)
 */


struct Node {
	int val;
	Node* next;
	Node* prev;
};

class Dequeue {
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
			last->next = tmp;
			tmp->prev = last;
			last = tmp;
		}
		Size++;
	}
	
	void deleteFirst(){ //O(1)
		if(head==NULL) {
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
		
		if(last==NULL) {
			cout<<"Empty"<<endl;
			return ;
		}
		if(head==last){
			head = last = NULL;
		}
		else {
			last = last->prev;
			last->next = NULL;
		}
		Size--;
	}
		
	int getFirst(){ //O(1)
		if(head==NULL) return -1;
		return head->val;
	}
	
	int getLast(){ //O(1)
		if(last==NULL) return -1;
		return last->val;
	}
	
	bool isEmpty(){ //O(1)
		return head==NULL;
	}
	
	int size(){ //O(1)
		return Size;
	}
	
	void erase(){ //O(n)
		last = NULL;
		while(head!=NULL){
			Node* tmp = head;
			head = head->next;
			free(tmp);
		}
		Size = 0;
	}
	
	void print(){ //O(n)
		Node* tmp ;
		tmp = head;
		
		while(tmp!=NULL){
			cout<<tmp->val<<" ";
			tmp = tmp->next;
		}
		cout<<endl;
	}
};


int main(){
	
	Dequeue dq;
	
	dq.insertFirst(1);
	dq.insertFirst(2);
	dq.insertFirst(3);
	
	dq.print();
	dq.erase();
	dq.print();
	
	dq.insertLast(4);
	dq.insertLast(5);
	
	dq.print();
	
	cout<<dq.getFirst()<<endl;
	cout<<dq.getLast()<<endl;
	
	dq.deleteFirst();
	dq.print();
	
	dq.deleteLast();
	dq.print();
	
	dq.erase();
	dq.print();
	
	return  0;
}
