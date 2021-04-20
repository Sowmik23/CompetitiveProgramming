#include <bits/stdc++.h>
using namespace std;


vector<int> bubble_sort(vector<int> nums){
	int i, j, n = nums.size(), tmp;
	
	for(i=0;i<n-1;i++){
		bool flag = false;
		for(j=0;j<n-i-1;j++){
			if(nums[j]>nums[j+1]){
				//swap
				flag = true;
				tmp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = tmp;
			}
		}
		if(flag==false) break;
	}
	
	return nums;
}


int main(){
	
	vector<int> v;
	
	v = { 45, 34, 2, 7, 1, 9, 2,3 };
	
	v = bubble_sort(v);
	
	for(auto i: v){
		cout<<i<<" ";
	}
	cout<<endl;
	
	return 0;
}
