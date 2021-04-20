#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       /* unordered_map<int, int> ump;
        
        for(int i=0;i<nums.size();i++){
			
            if(ump.find(nums[i])!=ump.end() and i-ump[nums[i]]<=k ){
                return true;
            }
            ump[nums[i]] = i;
        }
        return false;
        */
        
        unordered_set<int> ust;
        
        for(int i=0;i<nums.size();i++){
			
			if(i>k){
                ust.erase(nums[i-k-1]);
            }
            if(ust.count(nums[i])) return true;
            
            ust.insert(nums[i]);
        }
        return false;
    }
};


int main(){
	
	Solution s;
	vector<int> v;
	
	v = {3,4, 5, 6, 7, 2,3, 4, 3};
	
	bool f = s.containsNearbyDuplicate(v, 3);
	cout<<f<<endl;
	
	return 0;
}
