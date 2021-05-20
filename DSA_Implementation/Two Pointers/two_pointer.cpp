#include <bits/stdc++.h>
using namespace std;

/*
Problem:
Given two arrays (A and B) sorted in ascending order, 
and an integer x. we need to find i and j, such that a[i] + b[j] 
is equal to X.

*/


void twoPointer(vector<int> a, vector<int>b, int x){
	int n = a.size(), m = b.size();
	
	for(int i = 0, j = m - 1; i < n && j >= 0;) {
		if(a[i] + b[j] > x) {
			j--;
		} 
		else if(a[i] + b[j] < x) {
			i++;
		} 
		else {
			printf("%d + %d = %d\n", a[i], b[j], x);
			i++; j--;
		}
	}
}



int main(){
	
	vector<int> a = {2, 3, 4, 5, 6, 7};
	vector<int> b = {4, 5, 6, 7};
	
	int x = 13;
	twoPointer(a, b, x);
	
	return 0;
}
