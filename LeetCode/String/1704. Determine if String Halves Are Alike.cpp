class Solution {
public:
    bool halvesAreAlike(string s) {

        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i]) and i<s.size()/2) cnt++;
            else if(isVowel(s[i]) and i>=s.size()/2) cnt--;
        }
        return cnt==0;
    }
private:
    bool isVowel(char ch){
        return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U';
    }
};
