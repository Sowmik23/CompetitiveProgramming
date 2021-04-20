#include <bits/stdc++.h>
using namespace std;


struct Node {
	string val;
	Node* next;
	
	Node(string value, Node *next){
		this->val = value;
		this->next = next;
	}
};

class LinkedList {
	Node *head;
	public:
	LinkedList(){
		this->head = nullptr;
	}
	
	void insert(string value){
		this->head = new Node(value, this->head);
	}
	
	bool search(string value){
		Node *current = this->head;
		while(current!=nullptr){
			if(current->val==value){
				return true;
			}
			current = current->next;
		}
		return false;
	}
	
	bool deleteValue(string value){
		
		if(this->head==nullptr) return false;
		else if(this->head->val==value){
			///delete head
			this->head = this->head->next;
			return true;
		}
		
		Node *prev = this->head;
		Node *current = this->head->next;
		while(current!=nullptr){
			if(current->val==value){
				prev->next = current->next;
				return true;
			}
			prev = current;
			current = current->next;
		}
		return false;
	}
	
	void print(){
		Node *current = this->head;
		while(current!=nullptr){
			cout<<current->val<<" --> ";
			current = current->next;
		}
		cout<<endl;
	}
};


int main(){
	
	LinkedList ll;
	
	ll.insert("sowmik");
	ll.insert("334");
	ll.insert("9");
	ll.insert("0");
	
	ll.print();
	
	
	return 0;
}
