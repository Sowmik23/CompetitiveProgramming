// 2141. Maximum Running Time of N Computers
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        //sorting + prefix sum
        //Time: O(mlogm)
        //Space: O(m)

/*
        int m = batteries.size();
        long long extra = 0;

        sort(batteries.begin(), batteries.end());
        for(int i=0;i<m-n;i++){
            extra +=batteries[i];
        }

        vector<int> liveNpc;
        for(int i=m-n;i<m;i++){
            liveNpc.push_back(batteries[i]);
        }

        for(int i=0;i<n-1;i++){
            if(extra<(long) (i+1)*(liveNpc[i+1]-liveNpc[i]) ){
                return liveNpc[i]+(extra/(i+1));
            }
            extra -=(long) (i+1)*(liveNpc[i+1]-liveNpc[i]);
        }
        return liveNpc[n-1] + (extra/n);
    */

        //Binary Search
        //Time: O(mlogk)
        //Space: O(1)

        long long low = 1, high = 0;
        for(auto& bp: batteries) high+=bp;
        high = high/n;

        while(low<high){
            long mid = high - (high-low)/2;
            long extra = 0;
            for(auto& bp: batteries){
                extra += min(bp, mid);
            }

            if(extra>=(long)n*mid) low = mid;
            else high = mid-1;
        }
        return low;
    }
private:
    long min(long a, long b){
        if(a<=b) return a;
        return b;
    }
};