// 1370. Increasing Decreasing String
class Solution {
public:
    string sortString(string s) {
        
        unordered_map<int, int> mp;
        for(auto& ch: s){
            mp[ch-'a']++;
        }

        string res = "";
        bool flag = true;
        while(flag){
            bool f = false;
            for(int i=0;i<26;i++){
                if(mp.find(i)!=mp.end()){
                    if(mp[i]>0){
                        f = true;
                        res+= (i+'a');
                        mp[i]--;
                        if(mp[i]==0) mp.erase(i);
                    }
                }
            }
            if(!f) break;
            for(int i=25;i>=0;i--){
                if(mp.find(i)!=mp.end()){
                    if(mp[i]>0){
                        f = true;
                        res+= (i+'a');
                        mp[i]--;
                        if(mp[i]==0) mp.erase(i);
                    }
                }
            }
            if(!f) break;
        }
        return res;
    }
};