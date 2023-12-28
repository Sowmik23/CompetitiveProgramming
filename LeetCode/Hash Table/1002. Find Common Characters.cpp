// 1002. Find Common Characters
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        set<int> st;
        unordered_map<int, int> mp;
        for(int i=0;i<words.size();i++){
            set<int> newSt;
            unordered_map<int, int> newMp;
            for(auto& ch: words[i]){
                if(i==0) {
                    st.insert(ch-'a');
                    mp[ch-'a']++;
                }
                else {
                    if(st.count(ch-'a')>0) {
                        newSt.insert(ch-'a');
                        newMp[ch-'a']++;
                    }
                }
            }
            if(i!=0){
                set<int>::iterator newStIt;
                for(newStIt=newSt.begin(); newStIt!=newSt.end();newStIt++){
                    newMp[*newStIt] = min(mp[*newStIt], newMp[*newStIt]);
                }
                st = newSt;
                mp = newMp;
            }
        }

        vector<string> res;
        for(auto& m: mp){
            cout<<m.first<<" "<<m.second<<endl;
            int cnt = m.second;
            while(cnt){
                string tmp = "";
                tmp+=(m.first+'a');
                res.push_back(tmp);
                cnt--;
            }
        }
        return res;
    }
};