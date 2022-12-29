class Solution {
public:
    int longestPalindrome(vector<string>& words) {

        unordered_map<string, int> mp;
        for(auto& w: words) mp[w]++;

        bool flag = false;
        int cnt = 0;
        for(auto w: words){
            if(w[0]!=w[1]){
                string str = w;
                reverse(w.begin(), w.end());
                string rev = w;
                if(mp[rev]>0 and mp[str]>0){
                    cnt++;
                    mp[rev]--;
                    mp[str]--;
                }
            }
            else {
                if(mp[w]>1){
                    mp[w]-=2;
                    cnt++;
                }
                else if(mp[w]>0) flag = true;
            }
        }
        cnt = cnt*4;
        if(flag==true) cnt+=2;
        //cout<<cnt<<endl;
        return cnt;
    }
};
