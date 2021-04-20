#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      /* int n = nums.size();
        unordered_set<int> uset;
        for(int i=0;i<n;i++){
            if(uset.find(nums[i])==uset.end()){
                uset.insert(nums[i]);
            }
            else {
                return true;
            }
        }
        return false;*/
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) return true;
        }
        return false;
    }
};

int main(){
	
	Solution s;
	
	vector<int> v = {1, 5, -2, -4, 0};
	
	if(s.containsDuplicate(v)) cout<<"true"<<endl;
	else cout<<"false"<<endl;
	
	
	
	return 0;
	
}
