#include <bits/stdc++.h>
using namespace std;

/*
 * push(): O(1)
 * pop(): O(1)
 * top(): O(1)
 * size(): O(n)
 * print(): O(n)

*/

struct Node {
	int val;
	Node* next;
};

class Stack{
	Node* head = NULL;
	
public:
	void push(int val){ //O(1)
		Node* tmp = new Node;
		tmp->val = val;
		tmp->next = head;
		
		head = tmp;
	}
	
	void pop(){ //O(1)
		head = head->next;
	}
	
	void top(){ //O(1)
		cout<<head->val<<endl;
	}	
	
	int size(){
		if(head==NULL) return 0;
		Node* tmp;
		tmp = head;
		int cnt = 0;
		while(tmp!=NULL){
			cnt++;
			tmp = tmp->next;
		}
		//cout<<cnt<<endl;
		return cnt;
	}
	
	void print(){
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
	
	Stack stk;
	
	stk.push(2);
	stk.push(3);
	stk.push(4);
	stk.push(5);
	stk.push(6);
	
	stk.print();
	
	stk.pop();
	
	stk.print();
	stk.top();
	
	cout<<stk.size()<<endl;
	
	
	return 0;
}
