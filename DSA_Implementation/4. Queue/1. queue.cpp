#include <bits/stdc++.h>
using namespace std;


/*
 * push1(): O(1)
 * pop1(): O(n)
 * front1(): O(n)
 * 
 * push(): O(n)
 * pop(): O(1)
 * front(): O(1)
 * size(): O(n)
 * print(): O(n)

*/

struct Node {
	int val;
	Node* next;
};


class Queue{
	Node* head=NULL;
	
	public:
	void push1(int val){ //O(1)
		Node* tmp = new Node;
		tmp->val = val;
		tmp->next = head;
		head = tmp;
	}
	
	void pop1(){ //O(n)
		Node* tmp ;
		tmp = head;
		
		while(tmp->next->next!=NULL){
			tmp = tmp->next;
		}
		tmp->next = NULL;
	}

	void front1(){ //O(n)
		Node* tmp;
		tmp = head;
		while(tmp->next->next!=NULL){
			tmp = tmp->next;
		}
		cout<<tmp->next->val<<endl;
	}
	
	
	void push(int val){ //O(n)
		Node* tmp = new Node;
		tmp->val = val;
		tmp->next = NULL;
		
		if(head==NULL) head = tmp;
		else {
			Node* curr = head;
			
			while(curr->next!=NULL){
				curr = curr->next;
			}
			curr->next = tmp;
		}
	}
	
	void pop(){ //O(1)
		head = head->next;
	}
	
	void front(){ //O(1)
		cout<<head->val<<endl;
	}
	
	int size(){
		Node* tmp ;
		tmp = head;
		int cnt = 0;
		while(tmp!=NULL){
			tmp = tmp->next;
			cnt++;
		}
		return cnt;
	}
	
	void print(){
		Node* tmp = head;
		while(tmp!=NULL){
			cout<<tmp->val<<" ";
			tmp = tmp->next;
		}
		cout<<endl;
	}

};


int main(){
	
	Queue q;
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	
	q.print();
	
	q.front();
	
	q.pop();
	q.print();
	
	q.pop();
	q.print();
	
	q.pop();
	q.print();
	
	q.front();
	
	cout<<q.size()<<endl;
	
	return 0;
}
