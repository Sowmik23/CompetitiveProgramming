#include <bits/stdc++.h>
using namespace std;


/*
 * Heap Sort: heapify: O(logn), create and build heap is : O(n) andso total : O(n*logn)
 * Time: O(n*logn) : Best, Worst, Average
 * Space: O(1)
 * Method: Selection
 * Stable : NO
 */



class PriorityQueue {
	
public:
	PriorityQueue(vector<int> &heap, int n){
		int index = (n-2)/2;
		while(index>=0){
			heapify_down(heap, index--, n);
		}
	}
	
	int pop(vector<int> &heap, int size){
		if(size==0) return -1;
		
		int top = heap[0];
		heap[0] = heap[size-1];
		heapify_down(heap, 0, size-1);
		return top;
	}
	
private:
	void heapify_down(vector<int> &heap, int index, int size){
		int leftChild = 2*index + 1;
		int rightChild = 2*index + 2;
		
		int largest = index;
		
		if(leftChild<size and heap[leftChild]>heap[index]){
			largest = leftChild;
		}
		if(rightChild<size and heap[rightChild]>heap[largest]){
			largest = rightChild;
		}
		
		if(largest!=index){
			swap(heap[index], heap[largest]);
			heapify_down(heap, largest, size);
		}
	}
};

void heapSort(vector<int> &nums, int size){
	PriorityQueue pq(nums, size);

	while(size>0){
		nums[size-1] = pq.pop(nums, size);
		size--;
	}
}

int main(){
	
	vector<int> nums = {45, 12, 23, 654, 2, 123, 4};
	int n = nums.size();
	
	heapSort(nums, n);
	
	for(auto i : nums){
		cout<<i<<" ";
	}
	cout<<endl;
	
	return 0;
}
