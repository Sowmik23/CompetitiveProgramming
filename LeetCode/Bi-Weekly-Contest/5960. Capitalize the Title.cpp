class Solution {
public:
    string capitalizeTitle(string title) {
        
        stringstream ss(title);
        string word;
        
        string res="";
        
        while(ss>>word){
           // cout<<word<<endl;
            if(word.size()>2){
                word[0] = toupper(word[0]);
                for(int i=1;i<word.size();i++){
                    word[i] = tolower(word[i]);
                }
            }
            else {
                for(int i=0;i<word.size();i++){
                    word[i] = tolower(word[i]);
                }
            }
            res+=word;
            res+=" ";
           // cout<<word<<endl;
        }
        
        
        return res.substr(0, res.size()-1);
    }
};
