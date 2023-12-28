// 1630. Arithmetic Subarrays

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> res;
        for(int i=0;i<l.size();i++){
            vector<int> tmp(begin(nums)+l[i], begin(nums)+r[i]+1);
            if(check(tmp)) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
private:
    bool check(vector<int> &tmp){
        sort(tmp.begin(), tmp.end());
        int diff = tmp[1]-tmp[0];

        for(int i=2;i<tmp.size();i++){
            if(tmp[i]-tmp[i-1]!=diff) return false;
        }
        return true;
    }
};