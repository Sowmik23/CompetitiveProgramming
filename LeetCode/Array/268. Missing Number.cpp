#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*map<int, int> mp;
        int mx = -1;
        for(int i=0;i<nums.size();i++){
            int value = nums[i];
            mp[value] = 1;
            if(value>mx) mx = value;
        }
        
        int num;
        bool flag = false;
        for(int i=0;i<=mx;i++){
            if(mp[i]!=1){
                num = i;
                flag = true;
                break;
            }
        }
        if(flag==false) num = mx+1;
        return num;
        */
        
        int sum = 0;
        for(int i=0;i<nums.size();i++){
           sum+=nums[i];
        }
        
        int n = nums.size();
        int total = (n*(n+1))/2;
        
        int num = total-sum;
        
        return num;
    }
};


int main(){
	
	Solution s;
	vector<int> nums = {0,3, 2};
	int k = s.missingNumber(nums);
	
	cout<<k<<endl;
	
	return 0;
}
