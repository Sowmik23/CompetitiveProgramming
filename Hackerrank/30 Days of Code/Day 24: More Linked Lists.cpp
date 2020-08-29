#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	public:
		Node(int d){
			data = d;
			next = NULL;
		}
	};

Node* insert(Node *head, int data){
	Node* p = new Node(data);
	if(head ==NULL) head = p;
	else if(head->next==NULL) head->next = p;
	else {
		Node* tmp = head;
		while(tmp->next!=NULL){
			tmp= tmp->next;
		}
		tmp->next = p;
	}
	return head;
}

Node* removeDuplicates(Node *head){
	if(head == NULL || head->next==NULL) return head;
	if(head->data == head->next->data){
		head->next = head->next->next;
		removeDuplicates(head);
	}
	else removeDuplicates(head->next);
	
	return head;
}

void display(Node* head){
	Node *tmp = head;
	while(tmp){
		cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
}


int main(){
	Node *head = NULL;
	int t, data;
	cin>>t;
	while(t--){
		cin>>data;
		head = insert(head, data);
	}
	head = removeDuplicates(head);
	display(head);
	
	
	return 0;
}
