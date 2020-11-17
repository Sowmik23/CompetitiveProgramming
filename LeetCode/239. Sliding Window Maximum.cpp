#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     
        vector<int> v;
        int i;
        deque<int> dq(k);
        for(i=0;i<k;i++){
            while((!dq.empty()) and nums[dq.back()]<= nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        for( ;i<nums.size();i++){
            int mx = nums[dq.front()];
            v.push_back(mx);
            
            while((!dq.empty()) and dq.front() <= i-k){
                dq.pop_front();
            }
            while((!dq.empty()) and nums[dq.back()]<= nums[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        v.push_back(nums[dq.front()]);
        
        return v;
    }
};

/*
int main(){
	int arr = {1,3,-1,-3,5,3,6,7};
	int k = 3;

	vector<int> maxSlidingWindow1 = maxSlidingWindow(arr, k);

	for(int i=0;i<maxSlidingWindow1.size();i++){
		cout<<maxSlidingWindow[i]<<" ";
	}
	cout<<endl;

	return 0;
}
*/
