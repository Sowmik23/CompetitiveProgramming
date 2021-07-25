#include <bits/stdc++.h>
using namespace std;

/*
 * Stack
 * push(): O(1)
 * pop(): O(1)
 * top(): O(1)
 * size(): O(1)
 * empty(): O(1)
 */

#define private public

struct Node {
	int val;
	Node* next;
};


class Stack {
	Node* root = NULL;
	int Size = 0;
	
private:
	void push(int data){ //O(1)
		Node* tmp = new Node;
		tmp->val = data;
		
		if(root==NULL) root = tmp;
		else {
			tmp->next = root;
			root = tmp;
		}
		Size++;
	}
	
	void pop(){ //O(1)
		int data = root->val;
		root = root->next;
		cout<<data<<" is poped"<<endl;
		Size--;
	}
	
	int top(){ //O(1)
		return root->val;
	}
	
	bool empty(){ //O(1)
		return Size==0;
	}
	
	int size(){ //O(1)
		return Size;
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
	
	Stack stk;
	
	stk.push(1);
	stk.push(2);
	stk.push(3);
	
	stk.print();
	
	stk.pop();
	stk.print();
	
	cout<<"Stack top is: "<<stk.top()<<endl;
	cout<<"stack size is: "<<stk.size()<<endl;
	
	if(stk.empty()==1) cout<<"Stack is empty"<<endl;
	else cout<<"Stack is not empty"<<endl;
	
	return 0;
}
