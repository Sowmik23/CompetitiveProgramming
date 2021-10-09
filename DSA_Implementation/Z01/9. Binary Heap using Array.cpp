#include <bits/stdc++.h>
using namespace std;

//min heap
#define MAX 1005

int arr[MAX], n;

class Heap{
	public:
		void push(int val){ //O(logn) -->for pushing 1 value
			if(n==MAX) {
				cout<<"Heap Overflow"<<endl;
				return;
			}
			n++;
			arr[n] = val;
			
			heapify_up(n);
		}
		
		void heapify_up(int n){ //O(log(n))
			int m = n;
			int parent = m/2;
			if(arr[parent]>arr[m]){
				swap(arr[parent], arr[m]);
				heapify_up(parent);
			}
		}
		
		void pop(){  //O(logn)
			arr[1] = arr[n];
			n--;
			
			heapify_down(1);
		}
		
		void heapify_down(int i){ //O(logn)
			int left = 2*i;
			int right = 2*i+1;
			int m = i;
			if(left<=n and arr[m]>arr[left]){
				m = left;
			}
			if(right<=n and arr[m]>arr[right]){
				m = right;
			}
			if(m!=i){
				swap(arr[m], arr[i]);
				heapify_down(m);
			}
		}
		
		int top(){ //O(1)
			return arr[1];
		}
		
		int search(int val){
			for(int i=1;i<=n;i++){
				if(arr[i]==val) return i;
			}
			return -1;
		}
		
		void remove(int val){ //O(n)
			int index = search(val);
			
			if(index!=-1){
				arr[index] = arr[n];
				n--;
				
				heapify_down(index);
			}
			else {
				cout<<"val not found"<<endl;
			} 
		}
		
		bool empty(){ //O(1)
			return n<1;
		}
		
		void printHeap(){
			for(int i=1;i<=n;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	};


int main(){
	
	Heap priorityQueue;
	
	priorityQueue.push(3);
	priorityQueue.push(2);
	priorityQueue.push(1);
	priorityQueue.push(11);
	priorityQueue.push(8);
	
	priorityQueue.remove(5);
	priorityQueue.remove(11);
	
	
	while(!priorityQueue.empty()){
		cout<<priorityQueue.top()<<" ";
		priorityQueue.pop();
	}
	cout<<endl;
	
	
	return 0;
}
