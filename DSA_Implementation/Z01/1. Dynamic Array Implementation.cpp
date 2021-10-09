#include <bits/stdc++.h>
using namespace std;


//C++ implementation of Dynamic Array/Vector

template<class T>

class DynamicArray {
	private:
		T *arr;
		int max_size;
		int len;
		
	public:
		DynamicArray(){
			max_size = 1;
			arr = new T(max_size);
			len = 0;
		}
		
		//insert a new element to the end of the array
		void push(T val){
			if(isFull()){
				max_size = max_size*2;
				T *tmp_arr = new T[max_size];
				
				//move all elements to the temp array
				for(int i=0;i<len;i++){
					tmp_arr[i] = arr[i];
				}
				
				delete[] arr;
				
				arr = tmp_arr;
			}
			arr[len] = val;
			len++;
		}
		
		void pop(int index){
			for(int i=index;i<len;i++){
				arr[i] = arr[i+1];
			}
			len--;
		}
		
		int size(){
			return len;
		}
		
		bool isEmpty(){
			return len==0;
		}
		
		int get(int index){
			if(index<len and index>=0) return arr[index];
			else cout<<"Invalid index";
			return 0;
		}
		
		void clear(){
			for(int i=0;i<len;i++){
				arr[i] = NULL;
			}
			len = 0;
		}
		
		bool isFull(){
			return len==max_size;
		}
		
		void printArray(){
			for(int i=0;i<len;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
		
		
		~DynamicArray(){
			delete[] arr;
		}
	};


int main(){
	
	DynamicArray<int> arr;
	
	arr.push(1);
	
	arr.printArray();
	
	arr.push(2);
	arr.push(3);
	arr.push(4);
	arr.push(5);
	arr.push(6);
	
	arr.printArray();
	arr.pop(4);
	arr.printArray();
	cout<<"Size: "<<arr.size()<<endl;
	
	arr.push(7);
	arr.push(8);
	arr.push(9);
	arr.push(10);
	arr.printArray();
	arr.clear();
	arr.printArray();
	
	return 0;
}
