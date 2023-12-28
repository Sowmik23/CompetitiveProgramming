// 1138. Alphabet Board Path
class Solution {
public:
    string alphabetBoardPath(string target) {
        
        unordered_map<int, pair<int, int>> mp;
        int ch = 0;
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++){
                mp[ch] = {i, j};
                ch++;
            }
        }
        mp[ch] = {6,1};

        string res = "";
        int srcX = 1;
        int srcY = 1;
        char src = ' ';

        for(int i=0;i<target.size();i++){
            int x = mp[target[i]-'a'].first;
            int y = mp[target[i]-'a'].second;
// cout<<x<<" "<<y<<endl;
            int b = y-srcY;
            int a = x-srcX;
// cout<<a<<" "<<b<<endl;
            if(src=='z'){
                upDown(res, a);
                leftRight(res, b);
            }
            else {
                leftRight(res, b);
                upDown(res, a);
            }
            
            res+="!";
            srcY = y;
            srcX = x;
            src = target[i];
        }
        
        return res;
    }
private:
    void leftRight(string &res, int b){
        if(b>0){ 
            while(b){
                res+="R";
                b--;
            }
        }
        else {
            while(b){
                res+="L";
                b++;
            }
        }
    }
    void upDown(string &res, int a){
        if(a>0){
            while(a){
                res+="D";
                a--;
            }
        }
        else {
            while(a){
                res+="U";
                a++;
            }
        }
    }
};