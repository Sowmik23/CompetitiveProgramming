#include <bits/stdc++.h>
using namespace std;


class maxFrequencyStack {
	unordered_map<int, int> freqMap;   //contains the freq of elements
	unordered_map<int, stack<int>> setMap; //map elements with its frequency
	
	int maxFreq = 0;

public:	
	void push(int x){
		int f = freqMap[x] + 1;
		freqMap[x] = f;
		
		if(f>maxFreq) maxFreq = f;
		
		setMap[f].push(x);
	}
	
	int pop(){
		int top = setMap[maxFreq].top();
		setMap[maxFreq].pop();
		
		freqMap[top]--;
		
		if(setMap[maxFreq].size()==0){
			maxFreq--;
		}
		return top;
	}
};



int main(){
	
	maxFrequencyStack fs;
	
	fs.push(4);
	fs.push(6);
	fs.push(7);
	fs.push(6);
	fs.push(8);
	
	cout<<fs.pop()<<endl;
	cout<<fs.pop()<<endl;
	
	
	return 0;
}
