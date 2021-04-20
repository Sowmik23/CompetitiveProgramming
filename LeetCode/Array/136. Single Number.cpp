#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		/*
		 int n = nums.size();
        unordered_map<int, int> umap;
        int ans;
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
        }
        unordered_map<int, int> ::iterator it;
        
        for(it=umap.begin();it!=umap.end();it++){
            if(it->second==1) {
                ans = it->first;
                break;
            }
        }
        return ans;
        */
        
		
        /*
         int n = nums.size();
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans = ans ^ nums[i];
        }
        return ans;
        * */
        
        /*  //See the difference: Everithing shoud declare outside for loop
        int n = nums.size();
        
        int i, ans=0;
        for(i=0;i<n;i++){
            ans ^= nums[i];
        }
        return ans;
        */
    }
};



int main(){
	
	Solution s;
	vector<int> v;
	
	v = {-1};
	
	int f = s.singleNumber(v);
	cout<<f<<endl;
	
	return 0;
}
