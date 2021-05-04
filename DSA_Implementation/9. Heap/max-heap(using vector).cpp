#include <bits/stdc++.h>
using namespace std;

///max-heap implementation using vector 

//Actually heap and priority queue is same. just different name.

struct PriorityQueue {    ///this name also should be Heap
	private:
	vector<int> heap;
	
	int parent(int index){
		return index>>1;  ///same as i/2 : remember: bit is always faster
	}
	int left_child(int index){
		return index<<1; ///same as 2*i
	}
	int right_child(int index){
		return {(index<<1) + 1}; ///same as 2*i+1
	}
	
	
	void heapify_down(int index){
		int left = left_child(index);
		int right = right_child(index);
		
		int largest = index;
		if(left<size() and heap[left]>heap[index]){
			largest = left;
		}
		if(right<size() and heap[right]> heap[largest]){
			largest = right;
		}
		
		if(largest!=index){
			swap(heap[index], heap[largest]);
			heapify_down(largest);
		}
	}
	
	void heapify_up(int index){
		if(index and heap[parent(index)]<heap[index]){
			swap(heap[index], heap[parent(index)]);
			
			heapify_up(parent(index));
		}
	}
	
	
	public:
	unsigned int size(){
		return heap.size();
	}
	
	bool empty(){
		return size()==0;
	}
	
	void push(int val){
		heap.push_back(val);
		
		int index = size()-1;
		heapify_up(index);
	}
	
	void pop(){
		try{
			if(size()==0){
				throw out_of_range("Vector<X>::at() : index is out of range(Heap underflow)");
			}
			heap[0] = heap.back();  //replace the root of the heap with the last element of the vector
			heap.pop_back();
			
			heapify_down(0); //call heapify_down on the root node
		}
		catch(const out_of_range &oor){
			cout<<endl<<oor.what();
		}
	}
	
	int top(){
		try{
			if(size()==0){
				throw out_of_range("Vector<X>::at() : index is out of range(Heap underflow)");
			}
			
			return heap.at(0); //return the top/first element of vector
		}
		catch (const out_of_range &oor){
			cout<<endl<<oor.what();
		}
	}
};



int main(){
	
	PriorityQueue pq;
	
	pq.push(3);
	pq.push(1);
	pq.push(34);
	pq.push(67);
	pq.push(56);
	
	//print the heap
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
	cout<<pq.top()<<endl;
	
	pq.pop();
	
	pq.push(3);
	pq.push(1);
	pq.push(34);
	pq.push(67);
	pq.push(56);
	
	cout<<pq.size()<<endl;
	
	cout<<pq.top()<<endl;
	
	pq.pop();
	cout<<pq.top()<<endl;
	
	pq.pop();
	cout<<pq.top()<<endl;
	
	cout<<pq.empty()<<endl;
	
	
	
	
	return 0;
}
