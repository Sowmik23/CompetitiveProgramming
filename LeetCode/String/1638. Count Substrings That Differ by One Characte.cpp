// 1638. Count Substrings That Differ by One Character
class Solution {
public:
    int countSubstrings(string s, string t) {
        
        //// Wrong Answer
        // s = "abe"
        // t = "bbc"
        //Expected: 10
        //Result: 14
       /* 
        int n = t.size();
        unordered_map<int, vector<string>> mp;
        
        //find all substrings of t and map them
        for(auto& ch: t){  //1 length substring
            string str;
            str.append(1, ch);
            mp[1].push_back(str);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                string substring = t.substr(i, j);
                // cout<<substring<<endl;
                if(substring.size()>1) mp[substring.size()].push_back(substring);
            }
        }
        // cout<<"------Start--------"<<endl<<endl;;

        int cnt = 0;
        //now for each substring of s, check if char diff is 1
        int m = s.size();
        for(auto& ch: s){ //1 length substring
            string str;
            str.append(1, ch);
            // cout<<str<<endl;
            cnt+=isDifferOneChar(str, mp[1]);
            // cout<<endl;
        }
        for(int i=0;i<m;i++){
            for(int j=i+1;j<=m;j++){
                string substring = s.substr(i, j);
                // cout<<substring<<endl;
                if(substring.size()>1) cnt+=isDifferOneChar(substring, mp[substring.size()]);
                // cout<<endl;
            }
        }
        return cnt;
    }
private:
    int isDifferOneChar(string subStrOfS, vector<string> &list){
        // cout<<"--------------"<<endl;
        int cnt = 0;
        for(auto& str: list){
            // cout<<str<<endl;
            int diff = 0;
            for(int i=0;i<subStrOfS.size();i++){
                if(subStrOfS[i]!=str[i]) diff++;
                if(diff>1) break;
            }
            if(diff==1) cnt++;
        }
        // cout<<cnt<<endl;
        return cnt;
    }
    */

        int cnt = 0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                int x = i;
                int y = j;
                int diff = 0;
                while(x<s.size() and y<t.size()){
                    if(s[x]!=t[y]) {
                        diff++;
                        if(diff>1) break;
                    }
                    if(diff==1) cnt++;
                    x++;
                    y++;
                }
            }
        }
        return cnt;
    }
};
