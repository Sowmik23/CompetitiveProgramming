class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        //finding the maximum set bit 
        vector<int> bit(32, 0);
        
        for(int i=0;i<candidates.size();i++){
            int val = candidates[i];
            int j = 31;
            
            while(val>0){
                if(val&1==1) bit[j]++;
                j--;
                val = val>>1;    
            }
        }
        
        int res = 1;
        for(int i=0;i<32;i++){
            //cout<<bit[i]<<" ";
            res = max(res, bit[i]);
        }
        
        
        return res;
    }
};
