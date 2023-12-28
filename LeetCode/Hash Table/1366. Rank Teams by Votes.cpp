// 1366. Rank Teams by Votes
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        
        int n = votes[0].size();
        string res(votes[0]);

        vector<vector<int>> mp(26, vector<int> (n));

        for(auto& vote: votes){
            for(int i=0;i<n;i++){
                mp[vote[i]-'A'][i]++;
            }
        }
        sort(res.begin(), res.end(), [&](auto& a, auto& b){
           if(mp[a-'A']==mp[b-'A']) return a<b;
           return mp[a-'A']>mp[b-'A'];
        });

        return res;
    }
};	