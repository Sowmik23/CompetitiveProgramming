#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int n;
	long long x;
	scanf("%d", &n);
	vector<long long> nums;
	for(int i=0;i<n;i++){
		scanf("%lld", &x);
		nums.push_back(x);
	}
	

	
	int l = 0;
	int r = n-1;
	
	
	/*for(int i=0;i<nums.size();i++){
		cout<<nums[i]<<" ";
	}
	cout<<endl;*/
	
	long long rajib = 0, rakib = 0;
	
	int i=1;
	while(i<=n){
		if(i%2==1){ 
			if(nums[l]>=nums[r]){
				
				rajib+=nums[l];
				l++;
			}
			else {
				
				rajib+=nums[r];
				r--;
			}
		}
		else if(i%2==0) {
			if(nums[l]>=nums[r]){
				rakib+=nums[l];
				l++;
			}
			else {
				rakib+=nums[r];
				r--;
			}
		}
		i++;
	}
	
	
	//cout<<"Rajib "<<rajib<<" Rakib"<<rakib<<endl;


	if(rajib>rakib) cout<<rajib-rakib<<" "<<"Rajib"<<endl;
	else if(rajib<rakib) cout<<rakib-rajib<<" Rakib"<<endl;
	else cout<<rajib-rakib<<" Both Chocolates are same"<<endl;
	
	
	return 0;
}
