class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {

        priority_queue<int> pl, tr;

        for(auto& p: players) pl.push(p);
        for(auto& t: trainers) tr.push(t);

        int cnt = 0;
        while(!pl.empty() and !tr.empty()){
            int p = pl.top();
            int t = tr.top();
            if(p<=t){
                cnt++;
                pl.pop();
                tr.pop();
            }
            else {
                pl.pop();
            }
        }

        return cnt;
    }
};
