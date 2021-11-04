#include <bits/stdc++.h>
using namespace std;

// Time: O(nlogn)
// Auxiliary Space: O(1)

// In-place: Yes
// Method: Selection
// Stable: No, but you can make it stable

// Heapify: O(logn), create and build heap is O(n)
/// So total is O(nlogn)


//It is simillar to selection sort

/// Heapify procedure can be applied to a node only if its children 
/// nodes are heapified. So the heapification must be performed 
/// in the bottom-up order.


class priorityQueue{
	public:
		priorityQueue(vector<int> &nums, int size){
			int index = (size-2)/2;
			while(index>=0){
				heapifyDown(nums, index--, size);
			}
		}
		
		int pop(vector<int> &nums, int size){
			if(size==0) return -1;
			
			int top = nums[0];
			nums[0] = nums[size-1];
			heapifyDown(nums, 0, size);
			
			return top;
		}
		
		
	private:
		void heapifyDown(vector<int> &nums, int idx, int size){
			int leftChild = 2*idx+1;
			int rightChild = 2*idx+2;
			int m = idx;
			if(leftChild<size and nums[leftChild]>nums[idx]){
				m = leftChild;
			}
			if(rightChild<size and nums[rightChild]>nums[m]){
				m = rightChild;
			}
			if(m!=idx){
				swap(nums[m], nums[idx]);
				heapifyDown(nums, m, size);
			}
		}
	};


void heapSort(vector<int> &nums){
	
	int n = nums.size();
	priorityQueue pq(nums, n);
	
	while(n>0){
		nums[n-1] = pq.pop(nums, n);
		n--;
	}
}


int main(){
	
	vector<int> nums = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	heapSort(nums);
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
