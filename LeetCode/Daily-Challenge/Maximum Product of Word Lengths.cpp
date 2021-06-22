class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        /*
        ///approach-01: TLE
        int mx =  0;
        for(int i=0;i<words.size()-1;i++){
            
            for(int j=i+1;j<words.size();j++){
                
                if(isValid(words[i], words[j])){
                    int x = (words[i].size())*(words[j].size());
                    mx = max(mx, x);
                }
            }
        }
        
        return mx;
        */
        
        int res =0;
        vector<int> mask(words.size());
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                mask[i] |= 1<< (words[i][j]-'a');   //hash the word
            }
            
            for(int k=0;k<i;k++){
                if((mask[i] & mask[k])==0){ //that means no common word
                    int x = (int(words[i].size())*(words[k].size()));
                    
                    if(x>res) res = x;
                }
            }
        }
        
        return res;
    }
    
private:
    bool isValid(string str1, string str2){
        map<char, int> mp;
        for(auto i: str1){
            mp[i] = 1;
        }
        
        for(auto i: str2){
            if(mp[i]==1) return false;
        }
        return true;
    }
};
