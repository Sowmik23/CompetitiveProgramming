#include <bits/stdc++.h>
using namespace std;


//Circular Queue implementation using array
//Time : O(1) for both enQueue and deQueue

class circularQueue {
	int front, rear, size;
	int *arr;

public:
	circularQueue(int size){
		front = rear = -1;
		size = size;
		
		arr = new int[size];
	}
	
	void enQueue(int val){
		///check if queue is full or not
		if((front==0 and rear==size-1) or (rear==(front-1)%(size-1))){
			cout<<"Queue is full"<<endl;
			return ;
		}
		else if(front==-1){  ///insert the first value
			front = rear = 0;
			arr[rear] = val;
		}
		else if(rear==size-1 and front!=0){
			rear = 0;
			arr[rear] = val;
		}
		else {
			rear++;
			arr[rear] = val;
		}
	}
	
	int deQueue(){
		if(front==-1){
			cout<<"Queue is empty"<<endl;
			return -1;
		}
		
		int data = arr[front];
		arr[front] = -1;
		if(front==rear){
			front = -1;
			rear = -1;
		}
		else if(front==size-1){
			front = 0;
		}
		else front++;
		
		return data;
	}
	
	void displayQueue(){
		if(front==-1){
			cout<<"Queue is empty"<<endl;
			return;
		}
		if(front<=rear){
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<" ";
			}
		}
		else {
			for(int i=front;i<size;i++){
				cout<<arr[i]<<" ";
			}
			for(int i=0;i<=rear;i++){
				cout<<arr[i]<<" ";
			}
		}
		cout<<endl;
	}
};

//normal queue implementation 
//Time: O(1) for both push and pop

class normalQueue{
	int front, rear, size;
	
	int *arr;
	
public:
	normalQueue(int size){
		front = rear = -1;
		size = size;
		
		arr = new int[size];
	}
	
	void push(int val){
		if(rear ==size-1){
			cout<<"Queue overflow"<<endl;
		}
		else {
			if(front==-1) front = 0;
			
			rear++;
			arr[rear] = val;
		}
	}
	
	int pop(){
		if(front==-1 or front>rear){
			cout<<"Queue underflow"<<endl;
			return -1;
		}
		int data = arr[front];
		front++;
		return data;
	}
	
	void displayNormalQueue(){
		if(front==-1){
			cout<<"Queue is empty"<<endl;
			return;
		}
		else {
			for(int i=front;i<=rear;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	}	 
};


int main(){
	
	circularQueue q(20);
	
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	
	q.displayQueue();
	
	cout<<q.deQueue()<<endl;
	q.displayQueue();
	
	cout<<q.deQueue()<<endl;
	q.displayQueue();
	
	
	return 0;
}
