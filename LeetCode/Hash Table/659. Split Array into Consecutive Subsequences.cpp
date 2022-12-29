class Solution {
public:
    bool isPossible(vector<int>& nums) {

        unordered_map<int, int> mp, subSeq;
        for(auto& i: nums){
            mp[i]++;
        }

        for(auto& i: nums){
            if(mp[i]==0) continue;
            mp[i]--;
            if(subSeq[i-1]>0){
                subSeq[i-1]--;
                subSeq[i]++;
            }
            else if(mp[i+1]>0 and mp[i+2]>0){
                mp[i+1]--;
                mp[i+2]--;
                subSeq[i+2]++;
            }
            else return false;
        }


        return true;
    }
};
