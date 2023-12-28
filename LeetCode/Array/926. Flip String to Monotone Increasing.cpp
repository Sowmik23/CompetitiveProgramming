class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int totalOne = 0, totalZero = 0;
        for(auto& ch: s){
            if(ch=='0') totalZero++;
            else totalOne++;
        }

        int cnt1 =0, cnt0=0;
        int mn = min(totalOne, totalZero);

        for(int i=0;i<s.size();i++){

            if(s[i]=='0'){
                mn = min(mn, cnt1+totalZero-cnt0);
                cnt0++;
            }
            else {
                mn = min(mn, cnt1+totalZero-cnt0);
                cnt1++;
            }
        }
        return mn;
    }
};
