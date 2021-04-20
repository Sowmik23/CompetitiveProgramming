#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int i, n =nums.size();
        
       /* unordered_map<int, int> mp;
        for(i=0;i<n;i++){
            mp[nums[i]]++;
        }
        
        vector<int> v;
        for(const auto & it: mp){
            if(it.second==1) v.push_back(it.first);
        }
        return v;*/
        
       /* long long int res = 0;
        for(i=0;i<n;i++){
            res^=nums[i];
        }
        //0110 = 6
        //0010 = 2
        //0001 = 1  
        
        // while(res&idx==0){
        //   idx = res<<1;
        // } 
        
        // cout<<res<<endl;
        res&=-res;
        // https://www.quora.com/What-is-the-most-elegant-line-of-code-youve-seen-and-why
        // cout<<res<<endl;
        long long int idx = res;
        
        int one=0, zero=0;
        
        for(i=0;i<n;i++){
            if(idx&nums[i]){
                one ^= nums[i];
            }
            else {
                zero ^= nums[i];
            }
        }
        return {one, zero}; */
        
        //int i, n =nums.size();
        
        long long int res = 0;
        for(i=0;i<n;i++){
            res^=nums[i];
        }
        int idx=1;
        
        while((res&idx)==0){
          idx = idx<<1;
        } 
        cout<<idx<<endl;
        // cout<<res<<endl;
       // res&=-res;
        // https://www.quora.com/What-is-the-most-elegant-line-of-code-youve-seen-and-why
        // cout<<res<<endl;
        //long long int idx = res;
        
        int one=0, zero=0;
        
        for(i=0;i<n;i++){
            if(idx&nums[i]){
                one ^= nums[i];
            }
            else {
                zero ^= nums[i];
            }
        }
        return {one,zero};
    }
};


int main(){
	
	Solution s;
	vector<int> v;
	
	v = {-1};
	
	vector<int> k = s.singleNumber(v);
	//cout<<f<<endl;
	
	return 0;
}
