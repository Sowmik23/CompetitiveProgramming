class Solution {
public:
    int countVowelStrings(int n) {
   
        int cnt  = 0;
        vector<char> tmp;
        backTrack(tmp, cnt, n, 0);
        
        return cnt;
    }
private:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    void backTrack(vector<char> &tmp, int &cnt, int n, int pos){
        if(tmp.size()>n) return;
        
        if(tmp.size()==n){
            cnt++;
            return;
        }
        for(int i=pos;i<5;i++){
            tmp.push_back(vowels[i]);
            backTrack(tmp, cnt, n, i);
            tmp.pop_back();
        }
    }
};
