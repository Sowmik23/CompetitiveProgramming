class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int left = 0, right = 0;
        double avg;
        int sum = 0;
        int cnt = 0;
        double maxAvg=INT_MIN;
        
        while(right<nums.size()){
            sum+=nums[right];
            right++;
            cnt++;
            
            while(cnt>k){
                sum-=nums[left];
                left++;
                cnt--;
            }
           if(cnt==k){
                //cout<<sum<<endl;
               avg = (double)sum/k;
               maxAvg = max(maxAvg, avg);
            }
        }
        
        return maxAvg;
    }
};
