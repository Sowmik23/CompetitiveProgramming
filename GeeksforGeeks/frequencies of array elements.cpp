
//Time: O(n)

#include <bits/stdc++.h> 
using namespace std; 

void countFreq(int arr[], int n) 
{ 
	unordered_map<int, int> mp; 

	for (int i = 0; i < n; i++) 
		mp[arr[i]]++; 


	for (int i = 0; i < n; i++) { 
	if (mp[arr[i]] != -1) 
	{ 
		cout << arr[i] << " " << mp[arr[i]] << endl; 
		mp[arr[i]] = -1; 
	} 
	} 
} 

int main() 
{ 
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	
	countFreq(arr, n); 
	return 0; 
} 
