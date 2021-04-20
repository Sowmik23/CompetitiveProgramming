#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> mp;
        int mx = -999;
        int len = nums.size();
        for(int i=0;i<len;i++){
            if(nums[i]>mx ){
                mx = nums[i];
            }
            mp[nums[i]] = 1;   
        }
        
        int num;
        bool flag = true;
        for(int i=1;i<mx;i++){
            if(mp[i]!=1){
                num = i;
                flag = false;
                break;
            }
        }
        if(mx<1) num = 1;
        else if(flag==true) num = mx+1;
        return num;
    }
};

int main(){
	
	Solution s;
	vector<int> nums = {7,8,9,11,12};
	int k = s.firstMissingPositive(nums);
	
	cout<<k<<endl;
	
	return 0;
}
