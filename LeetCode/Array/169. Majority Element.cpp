#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      /*  int i, n = nums.size();
        
        unordered_map<int, int> umap;
        for(i=0;i<n;i++){
            umap[nums[i]]++;
        }
        
        int k = n/2;
        for(auto & it: umap){
            if(it.second>k) {
                //cout<<it.second<<" "<<it.first<<" "<<k<<endl;
                return it.first;
            }
        }
        return NULL;*/
        
        int i, n= nums.size(), cnt=0, major;
        for(i=0;i<n;i++){
            if(cnt==0){
                major = nums[i];
            }
            if(nums[i]==major) {
                cnt++;
            }
            else cnt--;
        }
        return major;
        
       /* int i, n= nums.size(), cnt=0, major=-1;
        for(i=0;i<n;i++){
            if(cnt==0 or nums[i]==major){
                major = nums[i];
                cnt++;
            }
            else cnt--;
        }
        return major;*/
    }
};

int main(){
	
	Solution s;
	vector<int> v;
	
	v = {-1};
	
	int k = s.majorityElement(v);
	cout<<k<<endl;
	
	return 0;
}
