class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        
        vector<long long> shift(shifts.size(), 0);
        string res = "";
        
        
        shift[shifts.size()-1] = shifts[shifts.size()-1];
        
        for(int i=shift.size()-2;i>=0;i--){
            shift[i] = (shifts[i]%26 + shift[i+1]%26)%26;
        }
        
        // for(int i=0;i<shifts.size();i++){
        //     cout<<shift[i]<<" ";
        // }
        
        for(int i=0;i<s.size();i++){
            
            
            res+= (s[i]-'a' + shift[i])%26 + 'a';
        }
        
        
        return res;
    }
};
