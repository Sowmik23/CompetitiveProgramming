class Solution {
public:
    int maxRepeating(string sequence, string word) {

        int cnt = 0;
        int res = 0;

        if(word.size()>sequence.size()) return 0;

        for(int i=0;i<=sequence.size()-word.size();i++){
            int cnt = 0;
            int x = i;
            while(1){
                if(sequence.substr(x, word.size())==word) {
                    cnt++;
                    x = x+word.size();
                    res = max(res, cnt);
                }
                else break;
            }
        }
        return res;
    }
};
