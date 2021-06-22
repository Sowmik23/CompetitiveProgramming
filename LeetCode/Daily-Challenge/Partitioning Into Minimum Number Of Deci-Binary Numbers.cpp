class Solution {
public:
    int minPartitions(string n) {
        
        int mx = -1;
        for(auto i: n){
            int k = i-'0';
            if(k>mx) mx = k;
        }
        
        return mx;
    }
};
