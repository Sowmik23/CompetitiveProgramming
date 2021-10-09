#include <bits/stdc++.h>
using namespace std;

///Simply doubly linked list

struct ListNode {
	int val;
	ListNode* next;
	ListNode* prev;
};


class Dequeue{
	private:
		ListNode* head = NULL;
		ListNode* tail = NULL;
		int size = 0;
		
	public:
		void enqueue(int val){  //O(1)
			ListNode* tmp = new ListNode;
			tmp->val = val;
			tmp->next = NULL;
			
			if(head==NULL){
				head = tail = tmp;
				return;
			}
			
			tail->next = tmp;
			tmp->prev = tail;
			tail = tmp;
			
			size++;
		}
		
		int dequeue(){  //O(1)
			ListNode* tmp = head;
			int data = head->val;
			head = head->next;
			delete(tmp);
			
			size--;
			return data;
		}
		
		bool empty(){
			return size<0;
		}
	};


int main(){
	
	Dequeue dq;
	dq.enqueue(1);
	dq.enqueue(2);
	dq.enqueue(3);
	dq.enqueue(4);
	dq.enqueue(5);
	
	while(!dq.empty()){
		cout<<dq.dequeue()<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
