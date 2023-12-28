class Solution {
public:
    string getHint(string secret, string guess) {

        unordered_map<int, int> sec;
        unordered_map<int,  int> gue;

        int cntA = 0;
        int cntB = 0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) {
                secret[i] = guess[i] = '#';
                cntA++;
            }
            if(secret[i]!='#') sec[secret[i]]++;
            if(guess[i]!='#') gue[guess[i]]++;
        }

        for(char i=0;i<=9;i++){
           // cout<<sec[i+48]<<" "<<gue[i+48]<<endl;
            cntB+= min(sec[i+48], gue[i+48]);
        }

        string res = to_string(cntA)+"A"+to_string(cntB)+"B";
        return res;
    }
};
