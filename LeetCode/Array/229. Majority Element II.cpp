#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       /* int i, n = nums.size();
        vector<int> v;
        unordered_map<int,int> umap;
        
        for(i=0;i<n;i++){
            umap[nums[i]]++;
        }
        
        for(const auto& it: umap){
            if(it.second>n/3) v.push_back(it.first);
        }
        return v; */
        
        int cnt1=0, cnt2=0, num1=-1, num2=-1;
        for(auto i: nums){
            if(i==num1){
                cnt1++;
            }
            else if(i==num2){
                cnt2++;
            }
            else if(cnt1==0){
                num1 = i;
                cnt1++;
            }
            else if(cnt2==0){
                num2 = i;
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        int a=0, b=0;
        for(auto i: nums){
            if(i==num1) a++;
            else if(i==num2) b++;
        }
        
        vector<int> ans;
        int n = nums.size()/3;
        
        if(a>n) ans.push_back(num1);
        if(b>n) ans.push_back(num2);
        
        return ans;
    }
};

int main(){
	
	Solution s;
	vector<int> v;
	
	v = {-1};
	
	vector<int> k = s.majorityElement(v);
	//cout<<k<<endl;
	
	return 0;
}
