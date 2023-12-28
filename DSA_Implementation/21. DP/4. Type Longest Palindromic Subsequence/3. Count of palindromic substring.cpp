class Solution {
public:
    int countSubstrings(string s) {

        //Time: O(n^2)
        //Space: O(1)

        int cnt = 0;
        for(int i=0;i<s.size();i++){

            int a = i;
            int b = i;
            while(a>=0 and b<s.size() and s[a]==s[b]){
                cnt++;
                a--;
                b++;
            }

            a = i;
            b = i+1;
            while(a>=0 and b<s.size() and s[a]==s[b]){
                cnt++;
                a--;
                b++;
            }
        }
        return cnt;
    }
};
