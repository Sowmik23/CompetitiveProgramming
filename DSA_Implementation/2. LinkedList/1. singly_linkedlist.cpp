#include <bits/stdc++.h>
using namespace std;

/*
 * insertFirst(): O(1)
 * insertLast(): O(n)
 * deleteValue(): O(n)
 * search(): O(n)
 * 
 * size():
 * print():
 */


struct Node {
	int val;
	Node* next;
};


class LinkedList{
	Node* head = NULL;
	
	public:
	void insertFirst(int val){ //O(1)
		Node* tmp = new Node;
		tmp->val = val;
		tmp->next = head;
		
		head = tmp;
	}
	
	void insertLast(int val){  //O(n)
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
	
	
	void deleteValue(int data){ //O(n)
		
		if(head->val==val) head = head->next;
		else {
			Node* curr;
			curr = head;
			while(curr->next!=NULL){
				if(curr->next->val==data){
					break;
				}
				else curr = curr->next;
			}
			if(curr->next==NULL) {
				cout<<data<<" not found"<<endl;
			}
			else if(curr->next->val==data){
				curr->next = curr->next->next;
				cout<<"Value deleted successfully!"<<endl;
			}
		}
	}
	
	void search(int val){
		Node* tmp;
		tmp = head;
		
		bool flag = false;
		while(tmp!=NULL){
			if(tmp->val==val) {
				cout<<val<<" found!"<<endl;
				flag = true;
				break;
			}
			tmp = tmp->next;
		}
		if(flag==false) cout<<val<<" not found!"<<endl;
	}
	
	int size(){ //O(n)
		Node* tmp;
		tmp = head;
		int cnt = 0;
		while(tmp!=NULL){
			tmp = tmp->next;
			cnt++;
		}
		return cnt;
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
	
	LinkedList ll;
	
	ll.insertFirst(1);
	ll.insertFirst(2);
	ll.insertFirst(3);
	
	
	ll.print();
	
	
	ll.insertLast(4);
	ll.insertLast(5);
	ll.insertLast(6);
	
	ll.print();
	
	ll.deleteValue(7);
	ll.print();
	ll.deleteValue(4);
	ll.print();
	
	ll.search(1);
	ll.search(10);
	
	cout<<ll.size()<<endl;
	
	return 0;
}
