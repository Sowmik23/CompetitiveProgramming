#include <bits/stdc++.h>
using namespace std;

/*
 * Circular Queue
 * 
 * enqueue(): O(1)
 * dequeue(): O(1)
 */



#define private public

struct Node {
	int val;
	Node* next;
	Node* prev;
};


class CircularQueue{
	
private:
	Node* root = NULL;
	Node* tail = NULL;
	int Size=0;
	
	void enqueue(int data){ //O(1)
		Node* tmp = new Node;
		tmp->val = data;
		
		if(root==NULL){
			root = tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tmp;
			tail->next = root;
		}
		Size++;
	}
	
	void dequeue(){ //O(1)
		if(root==NULL) {
			cout<<"Queue is empty"<<endl;
			return ;
		}
		int d = root->val;
		root = root->next;
		tail->next = root;
		cout<<d<<" is deleted"<<endl;
		Size--;
	}
	
	
	void print(){
		if(Size==0){
			cout<<"Queue is empty"<<endl;
			return ;
		}
		Node* curr = root;
		while(curr->next!=root){
			cout<<curr->val<<" ";
			curr = curr->next;
		}
		cout<<curr->val<<endl;
	}
};


int main(){
	
	CircularQueue cq;
	
	cq.enqueue(1);
	cq.enqueue(2);
	cq.enqueue(3);
	
	cq.print();
	
	cq.dequeue();
	
	cq.print();
	cq.dequeue();
	cq.print();
	cq.dequeue();
	cq.print();
	
	return 0;
}

