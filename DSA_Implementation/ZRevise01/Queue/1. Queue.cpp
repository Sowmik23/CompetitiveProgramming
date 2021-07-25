#include <bits/stdc++.h>
using namespace std;

/*
 * Queue
 * push(): O(1)
 * pop(): O(1)
 * front(): O(1)
 * size(): O(1)
 * empty(): O(1)
 */

#define private public

struct Node {
	int val;
	Node* next;
	Node* prev;
};


class Queue {
	Node* root = NULL;
	Node* tail = NULL;
	int Size = 0;

private:
	void push(int data){
		Node* tmp = new Node;
		tmp->val = data;
		tmp->next = NULL;
		
		if(root==NULL){
			root = tail = tmp;
		}
		else {
			tail->next = tmp;
			tail = tmp;
		}
		Size++;
	}
	
	int front(){
		return root->val;
	}
	
	void pop(){
		int data = root->val;
		root = root->next;
		cout<<data<<" is poped."<<endl;
		Size--;
	}
	
	int size(){
		return Size;
	}

	bool empty(){
		return Size==0;
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
		


int main(){
	
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	
	q.print();
	
	q.front();
	q.pop();
	q.print();
	
	cout<<"Front val: "<<q.front()<<endl;
	
	cout<<"Size: "<<q.size()<<endl;
	if(q.empty()==1) cout<<"Queue is empty"<<endl;
	else cout<<"Queue is not empty"<<endl;
	
	return 0;
}
