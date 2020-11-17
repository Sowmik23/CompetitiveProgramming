#include <bits/stdc++.h>
using namespace std;


int main(){
	
	deque<int> q;
	
	int new_element, removed_element;
	
	scanf("%d", &new_element);
	
	/// adding an element
	while(!q.empty() and q.back()>new_element){
		q.pop_back();
	}
	q.push_back(new_element);
	
	
	/// finding the minimum
	int minimum = q.front();
	cout<<minimum<<endl;
	
	scanf("%d", &removed_element);
	
	/// removing an element
	if(!q.empty() and q.front()==removed_element){
		q.pop_front();
	}
	
	
	return 0;
}
