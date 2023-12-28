class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> res;
        
        for(auto& n: nums){
            string str = to_string(n);
            for(auto& ch: str){
                int x = ch-'0';
               // cout<<ch<<" "<<x<<" ";
                res.push_back(x);
            }
        }
        return res;
    }
};