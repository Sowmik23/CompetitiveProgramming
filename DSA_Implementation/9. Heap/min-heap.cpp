#include<bits/stdc++.h>
using namespace std;


///Complexity: O(n*logn)
//Implementation of min-heap using array



#define max_element 100009
int arr[max_element], n;


void insertH(int val){
	if(n==max_element) return ;
	n++;
	arr[n] = val;
	
	int parent, m = n;
	while(m>1){
		parent = m/2;
		if(arr[parent]>arr[m]){
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
	right = 2*idx + 1;
	
	if(left<=n and arr[left]<arr[m]){
		m = left;
	}
	if(right<=n and arr[right]<arr[m]){
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
	
		
	insertH(30);
	insertH(1);
	insertH(23);
	
	printHeap();
	
	insertH(45);
	insertH(4);
	
	printHeap();

	deleteH(23);
	
	printHeap();
	
	
	return 0;
}
