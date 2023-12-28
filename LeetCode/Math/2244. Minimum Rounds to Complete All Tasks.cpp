class Solution {
public:
    int minimumRounds(vector<int>& tasks) {

        unordered_map<int, int> mp;
        for(auto& task: tasks){
            mp[task]++;
        }

        int cnt = 0;
        for(auto& m: mp){
            //cout<<m.first<<" "<<m.second<<endl;
            int x = INT_MAX;
            if(m.second%3==0) x = min(x, (m.second/3));
            if(m.second%3==2 or (m.second/3>0 and m.second%3==1)) x = min(x, (m.second/3)+1);
            // if(m.second%2==0) x = min(x, (m.second)/2);
            // if(m.second%5==0) x = min(x, ((m.second/5)*2));
            // if(m.second%5==2 or m.second%5==3) x = min(x, ((m.second/5)*2)+1);
            // if(m.second%5==4) x = min(x, ((m.second/5)*2)+2);
            if(x==INT_MAX) return -1;
            cnt+=x;
        }
        return cnt;
    }
};
