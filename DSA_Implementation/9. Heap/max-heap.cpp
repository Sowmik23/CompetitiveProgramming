#include <bits/stdc++.h>
using namespace std;

///implementation of heap using array
/*
#max-heap: insert , delete

Heap is a complete binary tree.
Every nodes having the element greater than or equal all of it's 
decendents. So, root have the largest value. This representation of heap 
is called max-heap.
Duplicates are allowed here. 

Min-heap is opposite of the max-heap. Root has the smallest value. 
Height of a complete binary tree is log(n)
so heapify takes log(n) time. 

create a heap: n elements: O(n*logn)

Insertion cost: min = O(1)  max = log(n)
Delete operation: only delete the root.  
Deletion cost: max = log(n) ->heapify part(adjustment part)


///https://www.youtube.com/watch?v=HqPJF2L5h9U&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=32
*/

#define max_element 100000
int arr[max_element], n;

void insertH(int val){
	if(n==max_element) return ;
	n++;
	arr[n] = val;
	
	int parent, m = n;
	while(m>1){
		parent = m/2;
		if(arr[parent]<arr[m]){
			swap(arr[parent], arr[m]);
			m = parent;
		}
		else break;
	}
}

void printHeap(){
	for(int i=1;i<=n;i++){
		if(i!=1) cout<<" ";
		cout<<arr[i];
	}
	cout<<endl;
}

int searchH(int val){
	for(int i=1;i<=n;i++){
		if(arr[i]==val) return i;
	}
	return -1;
}

void Heapify(int idx){
	int left, right, m;
	m = idx;
	left = 2*idx;
	right = 2*idx+1;
	
	if(left<=n and arr[left]>arr[m]){
		m = left;
	}
	if(right<=n and arr[right]>arr[m]){
		m = right;
	}
	if(m!=idx){
		swap(arr[m], arr[idx]);
		Heapify(m);
	}
}	
	

void deleteH(int val){
	int p = searchH(val);
	arr[p] = arr[n];
	n--;
	
	Heapify(p);
}


int main(){
	
	
	
	insertH(10);
	insertH(5);
	insertH(20);
	insertH(50);
	
	printHeap();
	
	int k = searchH(10);
	if(k!=-1) cout<<"Value found at index: "<<k<<endl;
	else cout<<"Not found!"<<endl;
	
	deleteH(20);
	
	printHeap();
	
	deleteH(50);
	printHeap();
	
	return 0;
}
