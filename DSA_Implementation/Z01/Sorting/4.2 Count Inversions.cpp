#include <bits/stdc++.h>
using namespace std;


int merge(vector<int> &nums, int left, int mid, int right){
	int n1 = mid-left+1;
	int n2 = right-mid;
	vector<int> a(n1), b(n2);
	
	for(int i=0;i<n1;i++){
		a[i] = nums[left+i];
	}
	for(int i=0;i<n2;i++){
		b[i] = nums[mid+1+i];
	}
	
	int i=0, j=0, k=left;
	int cnt = 0;
	
	while(i<n1 and j<n2){
		if(a[i]<=b[j]){
			nums[k++] = a[i++];
		}
		else {
			cnt+=(mid-i+1);
			nums[k++] = b[j++];
		}
	}
	while(i<n1){
		nums[k++] = a[i++];
	}
	while(j<n2){
		nums[k++] = b[j++];
	}
	
	return cnt;
}


int mergeSort(vector<int> &nums, int left, int right){
	int res = 0;
	if(left<right){
		int mid = left+(right-left)/2;
		
		res+=mergeSort(nums, left, mid);
		res+=mergeSort(nums, mid+1, right);
		
		res+=merge(nums, left, mid, right);
	}
	
	return res;
}

int main(){
	
	//vector<int> nums = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 }; //39
	vector<int> nums = { 1, 20, 6, 4, 5 }; //5
	cout<<"Total inversion: "<<mergeSort(nums, 0, nums.size()-1)<<endl;
	for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}
