class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        //count indegree and outdegree of each node
        // if a node's indegree is n-1 then this is the town judge who don't trust anyone but n-1 nodes trust it
        
        
        vector<int> cnt(n+1, 0);
        for(int i=0;i<trust.size();i++){
            cnt[trust[i][0]]--;
            cnt[trust[i][1]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(cnt[i]==n-1) return i;
        }
        return -1;
    }
};
