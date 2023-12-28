// class Solution {
public:
    int maxUniqueSplit(string s) {
        
        int n = s.size();
        // set<string> st;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<=n;j++){
        //         string str = s.substr(i, j);
        //         cout<<str<<endl;
        //         st.insert(str);
        //     }
        // }
        // return st.size();

        backTrack(0, s, n);
        return cnt;
    }
private:
    int cnt = 0;
    set<string> st;
    void backTrack(int index, string s, int n){
        
        if(index==n){
            cnt = max(cnt, (int)st.size());
            return;
        }
        string str = "";
        for(int i=index;i<n;i++){
            str+=s[i];
            if(st.count(str)==0) {
                st.insert(str);
                backTrack(i+1, s, n);
                st.erase(str);
            }   
        }
        return;
    }
};1593. Split a String Into the Max Number of Unique Substrings
