class Solution {
public:
    string sortSentence(string s) {
        
        string word="";
        map<int, string> mp;
        
        for(int i=0;i<s.size();i++){
            // cout<<s[i]<<" ";
            if(ifdigit(s[i])==true){
                word.erase(remove(word.begin(), word.end(), ' '), word.end());
                mp[s[i]] = word;
                word = "";
            }
            else word+=s[i];
        }
        
        int cnt =0;
        int len = mp.size();
        string res="";
        for(auto i: mp) {
            // cout<<"kk"<<i.second<<" kk"<<endl;
            res+=i.second;
            if(cnt<len-1) res+=" ";
            cnt++;
        }
        
        return res;
    }
    
    private:
    bool ifdigit(char s){
        if(s=='1' or s=='2' or s=='3' or s=='4' or s=='5' or s=='6' or s=='7' or s=='8' or s=='9') return true;
        else return false;    
    }
};
