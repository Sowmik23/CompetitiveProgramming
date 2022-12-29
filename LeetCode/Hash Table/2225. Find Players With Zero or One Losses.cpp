class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        unordered_map<int, int> winner, loser;

        for(auto m: matches){
            winner[m[0]]++;
            loser[m[1]]++;
        }

        set<int> tmp1, tmp2;
        for(auto& w: winner){
            if(loser[w.first]==0) tmp1.insert(w.first);
            else if(loser[w.first]==1) tmp2.insert(w.first);
        }
        for(auto& l: loser){
            if(l.second==1) tmp2.insert(l.first);
        }

        vector<int> t1(tmp1.begin(), tmp1.end()), t2(tmp2.begin(), tmp2.end());
        return {t1, t2};
    }
};
