class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums.size();
        while(left<right){
            int mid = left+(right-left)/2;
            if(nums[mid]>=target) right = mid;
            else left = mid+1;
        }
        if(left<nums.size() and nums[left]<target) left++;
        //cout<<left<<endl;
        vector<int> res;
        for(int i=left;i<nums.size();i++){
            if(nums[i]==target) res.push_back(i);
            else break;
        }
        
        return res;
    }
};
