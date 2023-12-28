class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        vector<string> morseArray = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        set<string> st;
        for(auto& word: words){
            string str = "";
            for(auto& ch: word){
                str+=morseArray[ch-'a'];
            }
            st.insert(str);
        }

        return st.size();
    }
};
