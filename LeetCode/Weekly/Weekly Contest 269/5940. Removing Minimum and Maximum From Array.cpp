class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        if(nums.size()==1) return 1;
        if(nums.size()==2) return 2;
        int mn = INT_MAX;
        int minIdx;
        int mx = INT_MIN;
        int maxIdx;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mn){
                mn = nums[i];
                minIdx = i;
            }
            if(nums[i]>mx){
                mx = nums[i];
                maxIdx = i;
            }
        }
        cout<<minIdx<<" "<<maxIdx<<endl;
        
        int x = nums.size()-minIdx;
        int y = nums.size()-maxIdx;
        
        cout<<x<<" "<<y<<endl;
        
        int res;
        int mid;        
        int n = nums.size();
        
//         if(n%2==1){
//             mid = n/2;
//             if((minIdx<=mid and maxIdx<=mid)){
//                 res = max(minIdx, maxIdx)+1;
//             }
//             else if(minIdx>=mid and maxIdx>=mid){
//                 res = n-min(minIdx, maxIdx);
//             }
//             else {
//                 res = min(minIdx+1, x) + min(maxIdx+1, y);
//             }
//         } //3 4 5 6 7 8
//         else {
//             mid = n/2;
//             if(minIdx>=mid-1 and maxIdx>=mid-1){
//                 res = n-min(minIdx, maxIdx);
//             }
//             else if(minIdx<=mid and maxIdx<=mid){
//                 res = max(minIdx, maxIdx)+1;
//             }
//             else {
//                 res = min(minIdx+1, x) + min(maxIdx+1, y);
//             }
//         }
        
        int d1 = max(minIdx, maxIdx)+1;
        int d2 = n-min(minIdx, maxIdx);
        int d3 = min(minIdx+1, x) + min(maxIdx+1, y);
        
        res = min(d1, d2);
        res = min(res, d3);
        
        return res;
    }
};
