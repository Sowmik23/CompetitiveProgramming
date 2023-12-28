class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int n = strs[0].size();
        vector<vector<char>> mp(n, vector<char> (1, 'a'));

        for(auto& str: strs){
            for(int i=0;i<str.size();i++){
                if(mp[i][0]<=str[i] and mp[i][0]!='#') mp[i][0] = str[i];
                else mp[i][0] = '#';
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(mp[i][0]=='#') cnt++;
        }
        return cnt;
    }
};
