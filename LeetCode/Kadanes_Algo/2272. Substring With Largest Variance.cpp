// 2272. Substring With Largest Variance
class Solution {
public:
    int largestVariance(string s) {
        
        //Dynamic programming: Kadane's algorithm
        //Time: O(n*26*26)
        
        vector<int> cnt(26, 0);
        for(auto& ch: s) cnt[ch-'a']++;
        int globalMx = 0;

        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(i==j or cnt[i]==0 or cnt[j]==0) continue;
                int majorCnt = 0;
                int minorCnt = 0;
                int restMinor = cnt[j];

                char major = 'a'+i;
                char minor = 'a'+j;

                for(auto& ch: s){
                    if(ch==major) majorCnt++;
                    if(ch==minor) {
                        minorCnt++;
                        restMinor--;
                    }

                    //only update global max only if there is at least one minor
                    if(minorCnt>0) globalMx = max(globalMx, majorCnt-minorCnt);

                    //discard prev string if there is at least one remaining minor
                    if(majorCnt<minorCnt and restMinor>0){
                        majorCnt = 0;
                        minorCnt = 0;
                    }
                }
            }
        }
        return globalMx;
    }
};