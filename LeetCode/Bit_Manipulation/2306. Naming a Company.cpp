// 2306. Naming a Company
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        //TLE
        /*
        unordered_map<string,  bool> mp;
        for(auto& idea: ideas){
            mp[idea] = true;
        }

        long long res = 0;
        for(int i=0;i<ideas.size();i++){
            for(int j=i+1;j<ideas.size();j++){
                string a = ideas[i];
                string b = ideas[j];
                char tmp = a[0];
                a = b[0]+a.substr(1);
                b = tmp+b.substr(1);
                if(mp.find(a)==mp.end() and mp.find(b)==mp.end()) res+=2;
            }
        }
        return res;
        */

        unordered_set<string> st[26];
        for(auto& idea: ideas){
            st[idea[0]-'a'].insert(idea.substr(1));
        }

        long long res = 0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                auto s1 = st[i];
                auto s2 = st[j];
                int cnt = 0;
                for(auto& w: s1){
                    if(s2.count(w)>0) cnt++;
                }
                res+=2*((s1.size()-cnt)*(s2.size()-cnt));
            }
        }
        return res;
    }
};