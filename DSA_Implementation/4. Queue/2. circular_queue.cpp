#include <bits/stdc++.h>
using namespace std;

/* This is mainly circular linkedlist
 * 
 * enqueue: O(1)
 * dequeue: O(1)
 */



struct Node {
	int val;
	Node* next;
};

class CircularQueue {
	Node* head;
	Node* last;
	
	public:
	void enqueue(int val){
		Node* tmp = new Node;
		tmp->val = val;
		
		if(head==NULL){
			head = tmp;
		}
		else {
			last->next = tmp;
		}
		last = tmp;
		last->next = head;
	}
	
	void dequeue(){
		if(head==NULL){
			cout<<"Circular queue is empty!"<<endl;
		}
		else {
			int x = head->val;
			if(head==last){
				head = last = NULL;
			}
			else {
				head = head->next;
				last->next = head;
			}
			cout<<x<<" is deleted"<<endl;
		}
	}
	
	void print(){
		Node* tmp = head;
		while(tmp->next!=head){
			cout<<tmp->val<<" ";
			tmp = tmp->next;
		}
		cout<<tmp->val<<endl;
	}
};



int main(){
		
	CircularQueue cq;
	
	cq.enqueue(1);
	cq.print();
	cq.enqueue(2);
	cq.print();
	cq.enqueue(3);
	cq.print();
	cq.enqueue(4);
	
	
	cq.print();
	cq.dequeue();
	cq.print();
	cq.dequeue();
	cq.print();
	cq.dequeue();
	cq.print();
	
	
	return 0;
}
