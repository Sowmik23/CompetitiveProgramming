#include <bits/stdc++.h>
using namespace std;

/*
 * Implementation of max-heap
 * 
 * Time: O(n*logn) -> push, pop
 * Space: O(n);
 */

class PriorityQueue {
	vector<int> heap;
	
public:
	void push(int data){  //O(logn)
		heap.push_back(data);
		heapify_up(size()-1);
	}
	
	void pop(){ //O(logn)
		try {
			if(size()==0){
				throw out_of_range("Vector<X>::at() : index is out of range(Heap underflow)");
			}
			heap[0]= heap.back(); //replace the root of the heap with the last element of the vector
			heap.pop_back(); //delete the last element from vector
			
			heapify_down(0); //call this for root node
		}
		catch(const out_of_range &oor){
			cout<<endl<<oor.what();
		}
	}
	
	int top(){ //O(1)
		try{
			if(size()==0){
				throw out_of_range("Vector<X>::at() : index is out of range(Heap underflow)");
			}
			return heap.at(0); //return 0th index/root node value
		}
		catch (const out_of_range &oor){
			cout<<endl<<oor.what();
		}
		return 0;
	}	
	
	int size(){ //O(1)
		return heap.size();
	}
	
	bool empty(){ //O(1)
		return size()==0;
	}

private:
	void heapify_up(int index){
		
		if(index!=0){
			int parent = index/2;
			if(heap[parent] < heap[index]){
				swap(heap[parent], heap[index]);
				heapify_up(parent);
			}
		}
	}
	
	void heapify_down(int i){
		int leftChild = 2*i + 1;
		int rightChild = 2*i + 2;
		
		int largest = i;
		
		if(leftChild<size() and heap[leftChild]>heap[i]){
			largest = leftChild;
		}
		if(rightChild<size() and heap[rightChild]>heap[largest]){
			largest = rightChild;
		}
		if(largest != i){
			swap(heap[i], heap[largest]);
			heapify_down(largest);
		}
	}
};


int main(){
	
	PriorityQueue pq;
	
	pq.push(1);
	pq.push(2);
	pq.push(3);
	
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
	
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(8);
	pq.push(6);
	pq.push(4);
	
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
	
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(8);
	pq.push(6);
	pq.push(4);
	
	cout<<"Top is : "<<pq.top()<<endl;
	pq.pop();
	cout<<"Top is : "<<pq.top()<<endl;
	cout<<"Size: "<<pq.size()<<endl;
	
	if(pq.empty()==true) cout<<"isEmpty(): Yes"<<endl;
	else cout<<"isEmpty(): No"<<endl;
	
	return 0;
}
