class Solution {
    struct comp{
        bool operator()(pair<char, int> a, pair<char, int> b){
            return a.second<b.second;
        }
    };
public:
    string frequencySort(string s) {
        
        map<char, int> mp;
        string res = "";
        priority_queue<pair<char, int>, vector<pair<char, int>>, comp> pq;
        
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        
        for(auto i: mp){
            pq.push(i);
            //cout<<i.first<<" "<<i.second<<endl;
        }
        char ch;
        int cnt; 
        while(!pq.empty()){
            ch = pq.top().first;
            cnt = pq.top().second;
            while(cnt--) res+=ch;
            pq.pop();
        }
        
        return res;
    }
};
