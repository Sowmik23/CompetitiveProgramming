#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

//print the linked list
void printList(Node* head){
	if(head==NULL) cout<<"List is empty."<<endl;
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

//add node at the font of a linked list
void insertInFont(struct Node** head_ref, int data){
	Node* new_node = new Node();
	
	new_node->data = data;
	new_node->next = *head_ref;
	
	*head_ref = new_node;
}


//add node after a node
void insertAfterNode(struct Node* prev_node, int data){
	if(prev_node==NULL){
		cout<<"Previous node can't be null"<<endl;
		return ;
	}
	
	
	Node* new_node = new Node();
	
	new_node->data = data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}


//add node at the end of list
void insertatEnd(struct Node** head_ref, int data){
	Node* new_node = new Node();
	Node* tmp = *head_ref;
	
	new_node->data = data;
	new_node->next = NULL;
	
	if(*head_ref==NULL){
		*head_ref = new_node;
		return ;
	}
	
	while(tmp->next !=NULL){
		tmp = tmp->next;
	}
	tmp->next = new_node;
}



int main(){
	
	Node* head = NULL;
	int x, data;
	cout<<"Choose insertion type:";
	while(true){
		cout<<"\n\n1. Insert in font of linked list\n2. Insert end of the linked list.\n3. Insert after a given node.\n4. Print the list.\n5. Exit\n"<<endl;
		
		cin>>x;
		if(x>=1 and x<=3) {
			cout<<"Enter value to insert"<<endl;
			cin>>data;
		}
		
		if(x==1){
			insertInFont(&head, data);
		}
		else if(x==2){	
			insertatEnd(&head, data);
		}
		else if(x==3){
			//cout<<"Enter prev_node"<<endl;
			//cin>>prev_node;
			
			insertAfterNode(head->next, data);
			
		}
		else if(x==4) {
			printList(head);
		}
		else if(x==5){
			cout<<"You exit the program."<<endl;
			return 0;
		}
		else {
			cout<<"You give invalid number as input.Enter 1-3\n"<<endl;
		}
		
		if(x>=1 and x<=3){
			cout<<"After insertion the list is: "<<endl;
			printList(head);
		}
	}
	
	return 0;
}
