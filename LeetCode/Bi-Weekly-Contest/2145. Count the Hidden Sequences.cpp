class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        long long mx = 0, mn = 0, sum = 0;
        long long res = 0;
        
        for(auto& num: differences){
            sum+=num;
            
            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        
        return max(res, ((upper-mx)-lower + mn+1));
    }
};
