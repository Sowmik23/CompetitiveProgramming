#include <bits/stdc++.h>
using namespace std;


struct ListNode{
	int val;
	ListNode* next;
};

class Queue{
	private:
		ListNode* head = NULL;
		ListNode* tail = NULL;
		
		int size = 0;
		
	public:
		void push(int val){  //O(1)
			ListNode* tmp = new ListNode;
			tmp->val =val;
			tmp->next = NULL;
			
			if(head==NULL){
				head = tail = tmp;
			}
			
			tail->next = tmp;
			tail = tmp;
			
			size++;
		}
		
		void pop(){ //O(1)
			ListNode* tmp = head;
			head = head->next;
			delete(tmp);
			
			size--;
		}
		
		int front(){ //O(1)
			return head->val;
		}
		
		bool empty(){ //O(1)
			return size==0;
		}
		
		int Size() { //O(1)
			return size;
		}
	};



int main(){
	
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
	
	return 0;
}
