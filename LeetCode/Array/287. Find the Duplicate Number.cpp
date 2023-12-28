#include <bits/stdc++.h>
using namespace std;


//Floyd's Tortoise and Hare (Cycle Detection)
        for(int i=0;i<nums.size();i++){

            int x = abs(nums[i]);
            int y = nums[x];

            if(y<0) return x;
            nums[x] = -y;
        }
        return 0;

        //using hash set
        /*
        set<int> st;
        for(auto& num: nums){
            if(st.count(num)>0) return num;
            else st.insert(num);
        }
        return 0;
        */


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int num;
        // bool flag = false;
        // for(int i=0;i<nums.size()-1; i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j]) {
        //             flag = true;
        //            num= nums[i];
        //             break;
        //         }
        //     }
        //     if(flag==true) break;
        // }
        // return num;

        /*sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) return nums[i];
        }
        return 0;
        */

        int arr[30000] = {0};
        for(int i=0;i<nums.size();i++){
           if(arr[nums[i]]==0) arr[nums[i]]=1;
            else return nums[i];
        }
     return 0;
    }
};


int main(){

	Solution s;
	vector<int> nums = {2,3, 1, 2};
	int k = s.findDuplicate(nums);

	cout<<k<<endl;

	return 0;
}
