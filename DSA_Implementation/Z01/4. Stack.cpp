#include <bits/stdc++.h>
using namespace std;


struct ListNode{
	int val;
	ListNode* next;
};

class Stack{

	private:
		ListNode* head = NULL;
		int size = 0;
		
	public:
		void push(int val){
			ListNode* tmp = new ListNode;
			tmp->val = val;
			
			tmp->next = head;
			head = tmp;
			
			size++;
		}
		
		int top(){
			return head->val;
		}
		
		void pop(){
			if(size==0) {
				cout<<"Stack is empty"<<endl;
				return ;
			}
			ListNode* tmp = head;
			head = head->next;
			delete(tmp);
			
			size--;
		}
		
		bool isEmpty(){
			return size==0;
		}
		
		int Size(){
			return size;
		}
	};


int main(){
	
	Stack stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	
	while(!stk.isEmpty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
	cout<<endl;
	
	return 0;
}
