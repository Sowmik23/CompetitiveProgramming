class Solution {
public:
    bool checkZeroOnes(string s) {
        
        int mx = INT_MIN, mx1 = INT_MIN;
        int cnt0=0, cnt1 = 0;
        
        for(auto i: s){
            if(i=='0'){
                mx1 = max(cnt1, mx1);
                cnt1 = 0;
                //flag = true;
                cnt0++;
            }
            else if(i=='1'){
                mx = max(cnt0, mx);
                cnt1++;
                cnt0 = 0;
            }
        }
        mx = max(mx, cnt0);
        mx1 = max(mx1, cnt1);
        
       // cout<<mx<<" "<<mx1<<endl;
        if(mx1>mx) return true;
        else return false;
    }
};
