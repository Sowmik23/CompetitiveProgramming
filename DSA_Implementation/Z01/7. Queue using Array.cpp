#include <bits/stdc++.h>
using namespace std;



class Queue{
	private:
		int head, tail, size;
		int *arr;
		
	public:
		Queue(int size){
			this->size = size;
			arr = new int[size];
			head = tail = -1;
		}
		
		void push(int val){  //O(1)
			if(head==size-1){
				cout<<"Size overflow"<<endl;
				return;
			}
			if(head==-1){
				head = 0;
			}
			tail++;
			arr[tail] = val;
		}
		
		void pop(){ //O(1)
			
			head++;
		}
		
		int front(){  //O(1)
			if(head==-1 or head>tail){
				cout<<"Underflow"<<endl;
				return -1;
			}
			return arr[head];
		}
		
		bool empty(){  //O(1)
			return head==-1 or head>tail;
		}
	};


int main(){
	
	Queue q(50);
	
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
