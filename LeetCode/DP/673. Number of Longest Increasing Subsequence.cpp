class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int maxlen = 1;
        vector<int> len(nums.size(), 1);
        vector<int> cnt(nums.size(), 1);
        
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(len[j]+1>len[i]){
                        len[i] = len[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if(len[j]+1==len[i]){
                        cnt[i]+=cnt[j];
                    }
                }
            }
            if(maxlen<len[i]) maxlen = len[i];
        }
        
        int res = 0;
        for(int i=0;i<nums.size();i++){
            if(len[i]==maxlen) res+=cnt[i];
        }
        
        return res;
    }
};
