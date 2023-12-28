class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        sort(properties.begin(), properties.end(), [](auto& a, auto& b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];
        });

        int mx = INT_MIN;
        int res = 0;
        for(auto& p: properties){
            // cout<<p[0]<<" "<<p[1]<<endl;
            if(p[1]<mx) res++;
            mx = max(mx, p[1]);
        }

        return res;
    }
};
