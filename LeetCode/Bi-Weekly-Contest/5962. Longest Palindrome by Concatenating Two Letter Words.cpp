class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        //["lc","cl","gg"]
        //["ab","ty","yt","lc","cl","ab"]
        //["cc","ll","xx"]
        
        unordered_map<string, int> mp;
        for(auto& s: words){
            mp[s]++;
        }
        
        int cnt = 0;
        int same = 0;
        int sameOdd = 0;
        
        int dd = 0;
        priority_queue< pair<int, string>> tmp;
        
        for(auto& m: mp){
            cout<<m.first<<" "<<m.second<<endl;
            if(m.first[0]==m.first[1]){
                
                if(m.second%2==1){
                    //dd+=m.second;
                    //if(dd%2==1) sameOdd = dd;
                    
                    tmp.push({m.second, m.first});
                }
                else same+=m.second;
            }
        }
        
        bool flag = false;
        while(!tmp.empty()){
            flag = true;
            cout<<tmp.top().first<<endl;
            dd+=((tmp.top().first)-1);
            tmp.pop();
        }
        if(flag==true){
            sameOdd+=1;
            sameOdd+=dd;
        }
        
        for(auto& s: words){
            if(s[0]==s[1]){
                // if(mp[s]>=1){
                //     if(mp[s]%2==0) {
                //         same += mp[s];
                //         mp[s] = 0;
                //     }
                //     else {
                //         sameOdd = max(sameOdd, mp[s]);
                //         mp[s] = 0;
                //     }
                // }
            }
            else{
                string r = s;
                reverse(r.begin(), r.end());
                // if(mp[r]>0){
                //     cnt+=1;
                //     mp[r]--;
                //     mp[s]--;
                // }
                
                cnt+= 2*min(mp[r], mp[s]);
                mp[r] = 0;
                mp[s] = 0;
                
            }
        }
        cout<<cnt<<" "<<same<<" "<<sameOdd<<endl;
        return cnt*2 + same*2 + sameOdd*2;
    }
};
