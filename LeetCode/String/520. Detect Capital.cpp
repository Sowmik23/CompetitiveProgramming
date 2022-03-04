class Solution {
public:
    bool detectCapitalUse(string word) {
        
        bool firstCh = false;
        bool othersCh = false;
        if(word[0]>='A' and word[0]<='Z') firstCh= true;
        
        for(int i=1;i<word.size();i++){
            if(word[i]>='A' and word[i]<='Z'){
                if(firstCh==false) return false;
                if(i>1 and othersCh==false) return false;
                othersCh = true;
            }
            else {
                if(firstCh==true and othersCh==true) return false;
            }
        }
        
        return true;
    }
};
