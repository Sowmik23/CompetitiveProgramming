#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(int d){
			data = d;
			next = NULL;
		}
};

class Solution {
	public:
		Node* insert(Node* head, int data){
			Node* new_node = new Node(data);
			
			if(head!=NULL) {
				Node* tmp = head;
					
				while(tmp->next!=NULL){
					tmp = tmp->next;
				}
				tmp->next = new_node;
				return head;
			}
			else return new_node;
		}
		
		void display(Node* head){
			Node *tmp = head;
			while(tmp!=NULL){
				cout<<tmp->data<<" ";
				tmp = tmp->next;
			}
		}
};


int main(){
	
	Node* head = NULL;
	Solution mylist;
	int t, data;
	cin>>t;
	while(t--){
		cin>>data;
		head=mylist.insert(head, data);
	}
	mylist.display(head);
	
	
	return 0;
}
