class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        //Time : O(n^2)
        //SPace: O(n)
        
        int n = nums.size();
        vector<int> LIS(n, 1);
        
        int mx = 1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] and LIS[i]<=LIS[j]){
                    LIS[i] = LIS[j] + 1;
                    mx = max(mx, LIS[i]);                
                }
            }
        }
        
        // for(auto i: LIS) cout<<i<<" ";
        // cout<<endl;
        
        ///if they want the subsequence also then do it:
        int k = mx;
        string ans = "";
        for(int i=n-1;i>=0;i--){
            if(k>=1){
                if(LIS[i]==k) {
                  //  cout<<nums[i];
                    ans += to_string(nums[i]);
                    k--;
                }
            }
            else break;
        }
        reverse(ans.begin(), ans.end());
        cout<<"The subsequence is : "<<ans<<endl;
        
        
        ///Time: O(nlogn)
        
        
        
        return mx;
    }
};
