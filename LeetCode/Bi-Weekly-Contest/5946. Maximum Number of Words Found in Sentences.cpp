class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int mx = 0;
        for(int i=0;i<sentences.size();i++){
            
            stringstream ss(sentences[i]);
            string str;
            int cnt = 0;
            while(ss>>str){
                cnt++;
            }
            mx = max(mx, cnt);
        }
        
        return mx;
    }
};
