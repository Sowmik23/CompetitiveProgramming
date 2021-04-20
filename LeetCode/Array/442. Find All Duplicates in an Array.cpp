#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       /* int n = nums.size();
        int arr[99999] = {0};
        
        vector<int> v;
        
        for(int i=0;i<n;i++){
            if(arr[nums[i]]==0) arr[nums[i]]=1;
            else v.push_back(nums[i]);
        }
        return v; */
        
        int n = nums.size();
        vector<int> cnt(n+1, 0);
        vector<int> res;
        
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(cnt[i]==2){
                res.push_back(i);
            }
        }
        return res;
    }
};


int main(){
	
	Solution s;
	vector<int> nums = {2,3, 1, 2};
	vector<int> k = s.findDuplicates(nums);
	
	for(int i=0;i<k.size();i++) cout<<k[i]<<" ";
	
	return 0;
}
