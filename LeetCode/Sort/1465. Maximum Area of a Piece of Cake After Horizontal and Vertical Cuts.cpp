class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        long mod = 1e9+7;
        int n = horizontalCuts.size();
        int m = verticalCuts.size();
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int mxH = horizontalCuts[0];
        int mxW = verticalCuts[0];
        
        mxH = max(mxH, h-horizontalCuts[n-1]);
        mxW = max(mxW, w-verticalCuts[m-1]);
        
        for(int i=1;i<horizontalCuts.size();i++){
            mxH = max(mxH, horizontalCuts[i]-horizontalCuts[i-1]);
        }
        for(int i=1;i<verticalCuts.size();i++){
            mxW = max(mxW, verticalCuts[i]-verticalCuts[i-1]);
        }
        
        return ((mxH%mod)*(mxW%mod))%mod;
    }
};
