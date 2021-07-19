#include <bits/stdc++.h>
using namespace std;


struct Node {
	int val;
	Node* next;
};


class LinkedList {
	Node* head=NULL;
	Node* prev = NULL;
	
	//iterative method to reverse a linkedlist
	void reverse(Node* head){
		Node* curr = head;
		Node* prev = NULL;
		
		if(head==NULL) return;
		
		Node* tmp;
		while(curr!=NULL){
			tmp = curr->next;
			
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		head = prev;
	}
	
	//recursive method to reverse a linkedlist
	void reverseRecursive(Node* curr){
		if(curr->next==NULL){
			head = curr;
			return ;
		}
		
		reverseRecursive(curr->next);
		Node* tmp = curr->next;
		tmp->next = curr;
		curr->next = NULL;
	}
	
	void print(Node* head){
		Node* tmp =head;
		while(tmp!=NULL){
			cout<<tmp->val<<" ";
			tmp = tmp->next;
		}
		cout<<endl;
	}
};



int main(){
	
	
	
	
	return 0;
}
