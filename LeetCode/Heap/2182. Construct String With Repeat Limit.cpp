// 2182. Construct String With Repeat Limit
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        unordered_map<char, int> mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        priority_queue<pair<char, int>> pq;
        for(auto& m: mp){
            pq.push({m.first, m.second});
        }

        string res = "";
        while(!pq.empty()){
            int cnt = pq.top().second;
            char ch = pq.top().first;
            pq.pop();

            int len = min(cnt, repeatLimit);
            for(int i=0;i<len;i++){
                res+=ch;
            }
            if(cnt-len>0){
                if(!pq.empty()){
                    int cnt2 = pq.top().second;
                    char ch2 = pq.top().first;
                    pq.pop();

                    res+=ch2;
                    cnt2--;
                    if(cnt2>0) pq.push({ch2, cnt2});
                    pq.push({ch, cnt-len});
                }
                else return res;
            }
        }

        return res;   
    }
};