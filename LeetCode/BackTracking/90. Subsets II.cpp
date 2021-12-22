class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back({});
        
        for(auto& num: nums){
            int n = res.size();
            
            for(int i=0;i<n;i++){
                res.push_back(res[i]);
                res.back().push_back(num);
            }
        }
        
        set<vector<int>> st;
        for(auto& i: res){
            st.insert(i);
        }
        
        res = vector<vector<int>> ();
        for(auto& i: st){
            // for(auto& j: i){
            //     cout<<j<<" ";
            // }
            // cout<<endl;
            res.push_back(i);
        }
        
        return res;
    }
};
