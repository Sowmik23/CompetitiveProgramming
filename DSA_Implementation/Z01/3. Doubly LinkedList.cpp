#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode* prev;
};


class DoublyLinkedList{

	private:
		ListNode* head = NULL;
		ListNode* tail = NULL;
		int size = 0;
		
	public:
		void insertFirst(int val){ //O(1)
			ListNode* tmp = new ListNode;
			tmp->val = val;
			tmp->prev = NULL;
			
			if(head==NULL){
				head = tail = tmp;
				return;
			}
			
			tmp->next = head;
			head->prev = tmp;
			head = tmp;
			
			size++;
		}
		
		void insertLast(int val){ //O(1)
			ListNode* tmp = new ListNode;
			tmp->val = val;
			tmp->next = NULL;
			
			if(head==NULL) {
				head = tail = tmp;
				return;
			}
			
			tmp->prev = tail;
			tail->next = tmp;
			tail = tmp;
			
			size++;
		}
		
		void insertAfterVal(int nodeVal, int val){ //O(n)
			ListNode* tmp = new ListNode;
			tmp->val = val;
			
			ListNode* curr = head;
			while(curr->val!=nodeVal){
				curr=curr->next;
			}
			
			tmp->next = curr->next;
			curr->next->prev = tmp;
			
			tmp->prev = curr;
			curr->next = tmp;
			
			size++;
		}
		
		void deleteFirst(){ //O(1)
			ListNode* tmp = head;
			head = head->next;
			head->prev = NULL;
			delete(tmp);
			
			size--;
		}
			
		void deleteLast(){ //O(1)
			ListNode* tmp = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete(tmp);
			
			size--;
		}
		
		void deleteNode(int nodeVal){ //O(n)
			ListNode* curr = head;
			while(curr->val!=nodeVal){
				curr = curr->next;
			}
			ListNode* tmp = curr;
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
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
			ListNode* curr = head;
			cout<<"List: ";
			while(curr!=NULL){
				cout<<curr->val<<" ";
				curr = curr->next;
			}
			cout<<endl;
			
			ListNode* curr1 = tail;
			cout<<"Reverse List: ";
			while(curr1!=NULL){
				cout<<curr1->val<<" ";
				curr1 = curr1->prev;
			}
			cout<<endl;
		}
	};


int main(){
	
	DoublyLinkedList h;
	
	h.insertFirst(1);
	h.insertFirst(2);
	h.insertFirst(3);
	
	h.insertLast(1);
	h.insertLast(2);
	
	h.printList();
	
	cout<<endl;
	h.insertAfterVal(3, 6);
	h.printList();
	
	cout<<endl;
	h.deleteFirst();
	h.printList();
	
	cout<<endl;
	h.deleteLast();
	h.printList();
	
	cout<<endl;
	h.deleteNode(1);
	h.printList();
	
	
	return 0;
}
