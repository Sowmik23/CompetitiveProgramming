// 621. Task Scheduler
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<int, int> mp;
        int mxFreq = 0;
        for(auto& ch: tasks){
            mp[ch-'A']++;
            mxFreq = max(mxFreq, mp[ch-'A']);
        }

        int res = (mxFreq-1)*(n+1);
        for(auto& m: mp) if(m.second==mxFreq) res++;
        return max(tasks.size(), res);
    }
private:
    int max(int a, int b){
        return a > b ? a : b;
    }
};