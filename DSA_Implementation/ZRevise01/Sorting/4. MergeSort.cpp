#include <bits/stdc++.h>
using namespace std;

/*
 * Merge Sort
 * Time: O(n*logn) => worst, average, best
 * Space: O(n) => here extra space needed. 
 * Stable: yes
 * In-place: No: as need extra space
 * Class: comparison
 * 
 * Type : 2 (recursion, iterative): this code is recursive
 */


void merge(vector<int> &nums, int l, int m, int r){
	
	int n1 = m-l+1;
	int n2 = r-m;
	vector<int> a(n1), b(n2);
	
	for(int i=0;i<n1;i++){
		a[i] = nums[i+l];
	}
	for(int i=0;i<n2;i++){
		b[i] = nums[i+m+1];
	}
	
	int i=0, j=0;
	int k=l; //most important point. sometimes you forgot to fix it
	
	while(i<n1 and j<n2){
		if(a[i]<=b[j]){
			nums[k++] = a[i];
			i++;
		}
		else {
			nums[k++] = b[j];
			j++;
		}
	}
	
	while(i<n1){
		nums[k++] = a[i++];
	}
	while(j<n2){
		nums[k++] = b[j++];
	}
}



void mergeSort(vector<int> &nums, int l, int r){
	if(l<r){
		int mid = (l+r)/2;
		mergeSort(nums, l, mid);
		mergeSort(nums, mid+1, r);
		
		merge(nums, l, mid, r);
	}
}


int main(){
	
	vector<int> nums = {5, 4, 2, 7, 3, 1, 9, 8};
	
	int l = 0, r = nums.size()-1;
	mergeSort(nums, l, r);
	
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
