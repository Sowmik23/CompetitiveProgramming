// 2785. Sort Vowels in a String

class Solution {
public:
    string sortVowels(string s) {
        
        vector<char> vowels;
        for(auto& ch: s){
            if(isVowel(ch)) vowels.push_back(ch);
        }
        sort(vowels.begin(), vowels.end());

        int j = 0;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i] = vowels[j];
                j++;
            }
        }
        return s;
    }
private:
    bool isVowel(char ch){
        return ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U' or 
                ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
    }
};
	
	