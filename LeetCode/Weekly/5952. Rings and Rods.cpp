class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, set<char>> mp;
        
        for(int i=0;i<rings.size()-1;i+=2){
            mp[rings[i+1]-'0'].insert(rings[i]);
        }
        
        int cnt = 0;
        for(auto& i: mp){
            if(i.second.size()==3) cnt++;
            // for(auto& it: i.second){
            //     cout<<i.first<<" "<<it;
            // }
            // cout<<endl;
        }
        
        return cnt;
    }
};
