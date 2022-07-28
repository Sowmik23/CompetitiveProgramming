class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        set<int> st;
        for(auto& i: nums){
            st.insert(i);
        }
        
        int mx = 1;
        int cnt = 1;
        
        set<int> ::iterator it;
        it = st.begin();
        int x = *it;
        //cout<<*it<<" "<<x<<endl;
        ++it;
        
        for(;it!=st.end();it++){
            //cout<<*it<<" ";
            if(x+1==*it) {
                cnt++;
                x = *it;
            }
            else {
                x = *it;
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        mx = max(mx, cnt);
        
        return mx;
    }
};
