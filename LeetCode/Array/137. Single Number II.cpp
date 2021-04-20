#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*int i, n = nums.size();
        unordered_map<int, int> umap;
        unordered_map<int, int> ::iterator it;
        
        for(i=0;i<n;i++){
            umap[nums[i]]++;
        }
        
        for(it=umap.begin();it!=umap.end();it++){
            if(it->second==1){
                return it->first;
            }
        }
        return NULL;*/
        
        /*int i, n = nums.size(), ans=0;
        
        unordered_map<int, int> umap;
       
        for(i=0;i<n;i++){
            umap[nums[i]]++;
        }
        
        for(auto& it: umap){
            if(it.second==1){
                return it.first;
            }
        }
        return NULL;*/
        
        int i, n = nums.size(), ans=0;
        
        if(n==1) return nums[0];
        sort(nums.begin(), nums.end());
       
        
        for(i=0;i<n-1;i+=3){
           if(nums[i]!=nums[i+2]) return nums[i];
        }
        return nums[n-1];
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
