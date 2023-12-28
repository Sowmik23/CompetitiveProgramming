class Solution {
public:
    int bestClosingTime(string customers) {

        unordered_map<int, pair<int, int>> mp;

        int cntY=0, cntN=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y') cntY++;
            else cntN++;
            mp[i] = {cntY, cntN};
        }

        int res = 0, minP = INT_MAX;
        for(int i=0;i<customers.size();i++){

            int x = (cntY-mp[i].first);
            if(customers[i]=='Y') x+=1;
            int y = 0;
            if(i>0) y = mp[i-1].second;
           // cout<<i<<" "<<x<<" "<<y<<endl;

            if(minP>(x+y)){
                res = i;
                minP = x+y;
            }
        }
        if(minP>cntN){
            res = customers.size();
            minP = cntN;
        }


        return res;
    }
};
