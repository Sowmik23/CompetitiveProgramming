#include <bits/stdc++.h>
using namespace std;


//using priority queue we now implement max and min heap

void maxHeap(){
	priority_queue<int> pq;
	
	pq.push(4);
	pq.push(23);
	pq.push(2);
	pq.push(12);
	pq.push(8);
	
	
	cout<<"Max-Heap: ";
	///print the max heap now
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
	
	return;
}


void minHeap(){
	priority_queue<int, vector<int>, greater<int>> pq; //point to remember
	
	pq.push(4);
	pq.push(23);
	pq.push(2);
	pq.push(12);
	pq.push(8);
	
	
	cout<<"Min-Heap: ";
	///print the min heap
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
	return;
}


int main(){
	
	
	maxHeap();
	
	minHeap();
	
	return 0;
}
