#include <bits/stdc++.h>
using namespace std;


struct ListNode{
	int val;
	ListNode* next;
};

class LinkedList {

	private:
		ListNode* head = NULL;
		int size = 0;
		
	public:
		void insertFirst(int val){  //O(1)
			ListNode *tmp = new ListNode;
			tmp->val = val;
			
			tmp->next = head;
			head = tmp;
			
			size++;
		}
		
		void insertLast(int val){ //O(n)--->O(1)
			ListNode* tmp = new ListNode;
			tmp->val = val;
			tmp->next = NULL;
			if(head==NULL){
				head = tmp;
				return ;
			}
			ListNode* curr= this->head;
			while(curr->next!=NULL){
				curr = curr->next;
			}
			curr->next = tmp;
			
			size++;
		}
		
		void insertAfterVal(int nodeVal, int val){ //O(n)
			ListNode* tmp = new ListNode;
			tmp->val = val;
			
			ListNode* curr = head;
			
			while(curr->val!=nodeVal){
				curr = curr->next;
			}
			tmp->next = curr->next;
			curr->next = tmp;
			
			size++;
		}
		
		void deleteFirst(){ //O(1)
			if(head==NULL) {
				cout<<"List is empty()"<<endl;
				return ;
			}
			ListNode* tmp = head;
			head = head->next;
			
			delete(tmp);
			
			size--;
		}
		
		void deleteLast(){ //O(n)
			if(head==NULL) {
				cout<<"List is empty()"<<endl;
				return ;
			}
			ListNode* curr = head;
			if(head->next==NULL){
				ListNode* tmp = head;
				head = NULL;
				delete(tmp);
			}
			while(curr->next->next!=NULL){
				curr = curr->next;
			}
			ListNode* tmp = curr->next;
			curr->next = NULL;
			delete(tmp);
			
			size--;
		}
		
		void deleteAfter(int nodeVal){ //O(n)
			ListNode* curr = head;
			while(curr->val!=nodeVal){
				curr = curr->next;
			}
			ListNode* tmp = curr->next;
			curr->next = tmp->next;
			delete(tmp);
			
			size--;
		}
		
		int Size(){
			return size;
		}
		
		bool isEmpty(){
			return size==0;
		}	
		
		void printList(){ //O(n)
			ListNode* curr = this->head;
			while(curr!=NULL){
				cout<<curr->val<<" ";
				curr = curr->next;
			}
			cout<<endl;
		}
	};
			


int main(){
	
	LinkedList h;
	
	h.insertFirst(1);
	h.insertFirst(2);
	h.insertFirst(3);
	h.insertFirst(4);
	h.insertFirst(5);
	
	h.insertLast(7);
	h.insertLast(8);
	h.insertLast(9);
	h.insertAfterVal(7, 10);
	
	
	h.insertFirst(1);
	h.insertFirst(2);
	h.printList();
	
	h.deleteFirst();
	h.printList();
	h.deleteLast();
	
	h.printList();
	h.deleteAfter(2);
	h.printList();
	
	
	return 0;
}
