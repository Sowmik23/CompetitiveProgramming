class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {

        long long cnt = 0;
        long long curr = 0;
        unordered_map<long long, long long> mp;

        for(auto& t: tasks){
            curr++;
            if(mp.find(t)!=mp.end()){ //if exists in map
                long long prev = mp[t];
                if(curr-prev-1<space){
                    long long breakPoint = space - (curr-prev-1);
                    curr += breakPoint;
                }
                mp[t] = curr;
            }
            else {
                mp[t] = curr;
            }
        }

        return curr;
    }
};
