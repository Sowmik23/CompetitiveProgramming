#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      /*  map<int, int > mp;
        vector<int> v;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = 1;
        }
        
        for(int i=1;i<=nums.size();i++){
            if(mp[i]!=1) v.push_back(i);
        }
        
        return v;*/
        
        for(int i=0;i<nums.size();i++){
            int data = abs(nums[i]);
            nums[data-1] = -abs(nums[data-1]);
        }
        
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) v.push_back(i+1);
        }
        return v;
    }
};

int main(){
	
	Solution s;
	vector<int> nums = {0,3, 2};
	vector<int> k = s.findDisappearedNumbers(nums);
	
	for(int i=0;i<k.size();i++){
		cout<<k[i]<<" ";
	}
	
	return 0;
}
