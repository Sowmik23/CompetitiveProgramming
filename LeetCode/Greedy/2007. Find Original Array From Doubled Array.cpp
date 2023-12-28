class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {

        vector<int> res;

        sort(changed.begin(), changed.end());
        int n = changed.size();

        if(n%2) return {};

        //1 2 3 4 6 8
        //1 1 1 2 2 2
        //0 0 0 1

        unordered_map<int, int> mp;

        int i = 0;
        while(i<n and changed[i]==0) {
            if(i%2) res.push_back(0);
            i++;
        }
        if(i>0 and i%2) return {};

        for(;i<changed.size();i++){
            if(mp[i]==0){
                int lowerBnd = lower_bound(changed.begin(), changed.end(), 2*changed[i])-changed.begin();
                if(lowerBnd>=0 and lowerBnd<n){

                    int x = lowerBnd+mp[lowerBnd];
                    if(x<n and changed[x]==2*changed[i]){
                        res.push_back(changed[i]);
                        mp[lowerBnd]++;
                        if(mp[lowerBnd]!=1) mp[x] = -1;
                    }
                    else return {};
                }
               else return {};
            }
        }

        return res;
    }
};
