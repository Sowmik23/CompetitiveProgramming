class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<int, int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
        }
        
        vector<int> freq;
        for(auto& m: mp){
            freq.push_back(m.second);
        }
        sort(freq.begin(), freq.end(), greater<int> ());
        // 3 2 3 3 3 2 2 2 1
        // for(auto& n: freq) cout<<n<<" ";
        // cout<<endl;
        
        int cnt = 0;
        int x = freq[0];
        for(int i=1;i<freq.size();i++){
            if(x==freq[i]){
                cnt++;
                x = freq[i]-1;
            }
            else {
                if(freq[i]>x){
                    cnt+=(freq[i]-x);
                    if(x>0){
                        cnt+=1;
                        x = x-1;
                    } 
                }
                else x = freq[i];
            }
        }
        
        return cnt;
    }
};
