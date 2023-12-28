// 2423. Remove Letter To Equalize Frequency
class Solution {
public:
    bool equalFrequency(string word) {
        
        //Approach-01:
        //Time: O(n)
        //Space: O(1)
        /*
        vector<int> cnt(26, 0);
        for(auto& ch: word) cnt[ch-'a']++;

        int mxFreq = INT_MIN, mnFreq = INT_MAX;
        for(int i=0;i<26;i++){
            if(cnt[i]>0){
                mnFreq = min(mnFreq, cnt[i]);
            }
            mxFreq = max(mxFreq, cnt[i]);
        }
        
        int mxCnt=0, mnCnt=0;
        for(int i=0;i<26;i++){
            if(cnt[i]==mxFreq) mxCnt++;
            else if(cnt[i]==mnFreq) mnCnt++;
            else if(cnt[i]>0) return false;
        }
        
        
        if(mxFreq==mnFreq) return (mxCnt==1 or mxFreq==1); //abcd
        if(mnCnt==1 and mnFreq==1) return true;  //a
        if(mxFreq!=mnFreq+1 or mxCnt!=1) return false;

        return true;
        */

        //Approach-02
        //Time: O(n^2)
        //Space: O(1)

        /*
        for(int i=0;i<word.size();i++){
            if(isEqual(word, i)) return true;
        }
        return false;
        */

        //some optimization
        vector<bool> visited(26, false);
        for(int i=0;i<word.size();i++){
            if(!visited[word[i]-'a']){
                visited[word[i]-'a'] = true;
                if(isEqual(word, i)) return true;
            }
        }
        return false;
    }
private:
    bool isEqual(string word, int i){
        word.erase(i, 1);

        vector<int> cnt(26, 0);
        for(auto& ch: word) cnt[ch-'a']++;

        int prev = 0;
        for(int i=0;i<26;i++){
            if(cnt[i]>0){
                if(prev==0){
                    prev = cnt[i];
                }
                else {
                    if(prev!=cnt[i]) return false;
                }
            }
        }
        return true;
    }
};