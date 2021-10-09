#include <bits/stdc++.h>
using namespace std;

//min heap implementation

class Heap{
	private:
		vector<int> heap;
		int getParent(int idx){
			return (idx>>1); //same as idx/2;
		}
		int getleftChild(int idx) {
			return (idx<<1); //2*idx
		}
		int getrightChild(int idx) {
			return {(idx<<1)+1};
		}
		
	public:
		void push(int val){ //O(logn)
			heap.push_back(val);
			
			int n = heap.size()-1;
			heapify_up(n);
		}
		void heapify_up(int n){
			int parent = getParent(n);
			if(n and heap[parent]>heap[n]){
				swap(heap[n], heap[parent]);
				heapify_up(parent);
			}
		}
		
		void pop(){ //O(logn)
			try{
				if(Size()==0){
					cout<<"Heap is Empty"<<endl;
					return ;
				}
				heap[0] = heap.back();
				heap.pop_back();
				
				heapify_down(0);
			}
			catch(const out_of_range &oor){
				cout<<endl<<oor.what();
			}
		}
		void heapify_down(int i){
			int left = getleftChild(i);
			int right = getrightChild(i);
			int m = i;
			
			if(left<Size() and heap[left]<heap[m]){
				m = left;
			}
			if(right<Size() and heap[right]<heap[m]){
				m = right;
			}
			if(m!=i){
				swap(heap[m], heap[i]);
				heapify_down(m);
			}
		}
		
		int top(){ //O(1)
			try{
				if(Size()==0) {
					cout<<"Empty"<<endl;
					return 0;
				}
				return heap.at(0);
			}
			catch(const out_of_range &oor){
				cout<<endl<<oor.what();
			}
			return -1;
		}
		
		int search(int val){
			for(int i=0;i<Size();i++){
				if(heap[i]==val) return i;
			}
			return -1;
		}
		
		void remove(int val){ //O(n)
			int index = search(val);
			if(index==-1) {
				cout<<"Value not found"<<endl;
			}
			
			heap[index] = heap.back();
			heap.pop_back();
			
			heapify_down(index);
		}
		
		unsigned int Size(){
			return heap.size();
		}
		
		bool empty(){
			return Size()==0;
		}
		void print(){
			try{
				for(int i=0;i<Size();i++){
					cout<<heap.at(i)<<" ";
				}
				cout<<endl;
			}catch(const out_of_range &oor){
				cout<<endl<<oor.what();
			}
		}
	};


int main(){
	
	Heap pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(11);
	pq.push(6);
	pq.push(24);
	pq.push(3);
	
	cout<<pq.top()<<endl;
	pq.print();
	
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	
	return 0;
}
