class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        
        long long sum = 0;
        for(auto& i: matchsticks){
            sum+=i;
        }
        
        if(sum%4!=0) return false;
        
        int target = sum/4;
        
        vector<int> res(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int> ());
        
        // sort(matchsticks.rbegin(), matchsticks.rend());
        // for(auto& i: matchsticks) cout<<i<<" ";
        // cout<<endl;
        
        return backTrack(matchsticks, res, target, 0, matchsticks.size());
    }
private:
    bool backTrack(vector<int> &matchsticks, vector<int> &res, int target, int i, int n){
        if(i>=n){
            if(res[0]==res[1] and res[1]==res[2] and res[2]==res[3] and res[3]==target){
                return true;
            }
            return false;
        } 
        for(int j=0;j<4;j++){
            if(res[j]+matchsticks[i]>target) continue;
            res[j]+=matchsticks[i];
            
            if(backTrack(matchsticks, res, target, i+1, n)) return true;
            res[j]-=matchsticks[i];
        }
        
        return false;
    }
};
