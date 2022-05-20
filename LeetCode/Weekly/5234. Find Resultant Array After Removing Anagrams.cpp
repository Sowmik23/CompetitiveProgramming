class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        
        // for(int i=0;i<words.size();i++){
        //     sort(words[i].begin(), words[i].end());
        // }
        
        int i = 1;
        while(i<words.size()){
            string x = words[i]; 
            sort(x.begin(), x.end());
            string y = words[i-1];
            sort(y.begin(), y.end());
            if(x==y){
                words.erase(words.begin()+i);
            } 
            else i++;
        }
        
        return words;
    }
};
