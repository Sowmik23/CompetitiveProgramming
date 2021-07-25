#include <bits/stdc++.h>
using namespace std;

#define private public  ////here, this is used to access private method from main function

/*
 * insertFirst(): O(1)
 * insertLast(): O(n)
 * insertAfterVal(): O(n)
 * deleteValue(): O(n)
 * search(): O(n)
*/




struct Node {
	int val;
	Node* next;
};


class LinkedList {
	
private:
	Node* root = NULL;
	
	void insertFirst(int data){ //O(1)
		Node* tmp = new Node;
		tmp->val = data;
		tmp->next = root;
		
		root = tmp;
	}
	
	void insertLast(int data){ //O(n)
		Node* tmp = new Node;
		tmp->val = data;
		tmp->next = NULL;
		
		if(root==NULL) root = tmp;
		else {
			Node* curr = root;
			
			while(curr->next!=NULL){
				curr = curr->next;
			}		
			curr->next = tmp;
		}
	}
	
	void insertAfterVal(int targetVal, int data){ //O(n)
		Node* tmp = new Node;
		tmp->val = data;
		tmp->next = NULL;
		
		Node* curr = root;
		while(curr!=NULL){
			if(curr->val == targetVal){
				Node* node = curr->next;
				curr->next = tmp;
				tmp->next = node;
				break;
			}
			curr = curr->next;
		}
		if(curr==NULL) cout<<"TargetVal not found!"<<endl;
	}
		
	
	void deleteValue(int data){ //O(n)
		if(root==NULL) {
			cout<<data<<" value not found!"<<endl;
			return ;
		}
		else if(root->val==data){
			root = root->next;
			cout<<data<<" value deleted!"<<endl;
		}
		else {
			Node* curr = root;
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
				cout<<data<<" deleted successfully!"<<endl;
			}
		}
	}
	
	void search(int data){
		
		Node* curr = root;
		bool flag = false;
		
		while(curr!=NULL){
			if(curr->val == data){
				flag = true;
				break;
			}
			curr = curr->next;
		}
		if(flag==true) cout<<data<<" found"<<endl;
		else cout<<data<<" not found"<<endl;
	}
		
	void print(){ //O(n)
		Node* tmp = root;
		while(tmp!=NULL){
			cout<<tmp->val<<" ";
			tmp = tmp->next;
		}
		cout<<endl;
	}
};
	




int main(){
	
	LinkedList list;

	list.insertFirst(1);
	list.insertFirst(2);
	list.insertFirst(3);
	
	list.print();
	
	list.insertLast(4);
	list.insertLast(5);
	list.insertLast(6);
	
	list.print();
	
	list.deleteValue(1);
	
	list.print();
	list.search(-1);
	list.search(5);
	
	list.insertAfterVal(5, 7);
	list.print();
	
	
	return 0;
}
