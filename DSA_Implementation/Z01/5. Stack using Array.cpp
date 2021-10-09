#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
//or
//typedef int MAX = 1005;

class Stack{
	private:
		int arr[MAX];
		int size = 0;
	public:
		void push(int val){
			arr[size] = val;
			size++;
		} 
		
		void pop(){
			//int a = arr[size-1];
			size--;
			//delete(&a);
		}
		
		int top(){
			return arr[size-1];
		}
		
		bool empty(){
			return size==0;
		}
		
		int Size() {
			return size;
		}
	};
	

int main(){
	
	Stack stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	cout<<stk.top()<<endl;
	
	while(!stk.empty()){
		cout<<stk.top()<<" ";
		stk.pop();
	}
	cout<<endl;
	
	return 0;
}
