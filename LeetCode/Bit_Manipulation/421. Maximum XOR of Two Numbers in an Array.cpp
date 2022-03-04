class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        //Time: 32*n == O(N)
        //Space: O(n)
        
        int mx = 0, mask = 0;
        
        for(int i=31;i>=0;i--){
            mask = mask | (1<<i);
            
            set<int> st;
            for(auto& num: nums){
                st.insert(mask & num);
            }
            
            int tmp = mx | (1<<i);
            
            for(auto& s: st){
                if(st.find(tmp^s)!=st.end()){
                    mx = tmp;
                    break;
                }
            }
        }
        
        return mx;
    }
};
