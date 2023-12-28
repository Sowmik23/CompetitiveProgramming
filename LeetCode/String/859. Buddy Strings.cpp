// 859. Buddy Strings
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int n = s.size();
        int m = goal.size();
        if(n!=m) return false;

        vector<int> a(26,0), b(26, 0);

        bool flag = false;
        int diff = 0;

        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]) diff++;
            a[s[i]-'a']++;
            if(a[s[i]-'a']>=2) flag = true;
            b[goal[i]-'a']++;
        }
        if(a!=b) return false;

        return diff==2 or (diff==0 and flag) ;
    }
};