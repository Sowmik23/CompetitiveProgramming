// 2062. Count Vowel Substrings of a String

class Solution {
public:
    int countVowelSubstrings(string word) {
        
        int n = word.size();
        set<int> st;
        int cnt = 0;
        for(int i=0;i<n-4;i++){
            st.clear();
            for(int j=i;j<n;j++){
                if(isVowel(word[j])){
                    st.insert(word[j]-'a');
                    if(st.size()>=5) cnt++;
                }
                else break;
            }
        }
        return cnt;
    }
private:
    bool isVowel(char ch){
        return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
    }
};