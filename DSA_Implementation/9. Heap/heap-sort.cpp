#include <bits/stdc++.h>
using namespace std;

/*
#heap-sort implementation: O(n*logn)

1st: create a heap => O(n*logn)
2nd: delete all the element of the heap => O(n*logn)

Heapify: O(n)

heap is faster for implementing priority queue. 
*/

class PriorityQueue{
	
	int left_child(int index){
		return 2*index + 1;
	}
	int right_child(int index){
		return 2*index + 2;
	}
	
	void heapify_down(vector<int> &heap, int index, int size){
		int left = left_child(index);
		int right = right_child(index);
		
		int largest = index;
		
		if(left<size and heap[left]>heap[index]){
			largest = left;
		}
		if(right<size and heap[right]>heap[largest]){
			largest = right;
		}
		if(largest!=index){
			swap(heap[largest], heap[index]);
			heapify_down(heap, largest, size);
		}
	}
	
	
	public:
	PriorityQueue(vector<int> &heap, int n){
		///call heapify starting from the last internal node all the
		///way up to the root node
		int index = (n-2)/2;
		while(index>=0){
			heapify_down(heap, index--, n);
		}
	}
	
	int pop(vector<int> &heap, int size){
		if(size <=0) return -1;
		
		int top = heap[0];
		heap[0] = heap[size-1];
		
		heapify_down(heap, 0, size-1);
		
		return top;
	}
};


void heapSort(vector<int> &heap, int n){
	PriorityQueue pq(heap, n); //building priority queue
	
	while(n>0){
		heap[n-1] = pq.pop(heap, n);
		n--;
	}
}


int main(){
	
	vector<int> heap = {45, 23, 12, 654, 2, 123, 4};
	int n = heap.size();
	
	heapSort(heap, n);
	
	
	for(auto i: heap) cout<<i<<" ";
	cout<<endl;
	
	
	
	
	return 0;
}
