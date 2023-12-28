// 6312. Split With Minimum Sum

class Solution {
public:
    int splitNum(int num) {
        
        string str = to_string(num);
        sort(str.begin(), str.end());
        
        int x = str[0]-'0';
        int y = str[1]-'0';
        for(int i=2;i<str.size();i++){
            if(i%2==0){
                x = x*10 + str[i]-'0';
            }
            else y = y*10 + str[i]-'0';
        }
        
        //cout<<x<<" "<<y<<endl;
        return x+y;
    }
};