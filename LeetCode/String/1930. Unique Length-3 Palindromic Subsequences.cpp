// 1930. Unique Length-3 Palindromic Subsequences
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        // Save the first and last accurance of each character, 
        // and all the chars inbetween will form length-3 palindromes.


        vector<pair<int, int>> firstLastIdx(26, {-1, -1});

        for(int i=0;i<s.size();i++){
            if(firstLastIdx[s[i]-'a'].first==-1) firstLastIdx[s[i]-'a'].first = i;
            else firstLastIdx[s[i]-'a'].second = i;
        }

        int res = 0;
        for(int i=0;i<26;i++){ //for each 'a' to 'z' character
            if(firstLastIdx[i].first!=-1 and firstLastIdx[i].second!=-1){
                set<int> st;
                for(int j=firstLastIdx[i].first+1;j<firstLastIdx[i].second;j++){
                    st.insert(s[j]);
                }
                res+=st.size();
            }
        }
        return res;
    }
};