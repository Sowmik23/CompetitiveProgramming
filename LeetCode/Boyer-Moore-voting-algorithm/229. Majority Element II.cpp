// 229. Majority Element II

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        

        //Time: O(n)
        //Space: O(1)

        // Boyer-Moore majority vote algorithm O(N), O(1)
        
        // There can be at most k - 1 major element in an array if the major
        // element appears more than ⌊n / k⌋ times.

        if(nums.size()==0) return nums;
        
        int firstCandidate = INT_MAX;
        int secondCandidate = INT_MAX;
        int firstCount = 0;
        int secondCount = 0;

        // voting stage
        for(int i=0;i<nums.size();i++){
          if(nums[i]==firstCandidate) firstCount++;
          else if(nums[i]==secondCandidate) secondCount++;
          else if(firstCount==0) {
              firstCandidate = nums[i];
              firstCount = 1;
          }
          else if(secondCount==0) {
              secondCandidate = nums[i];
              secondCount = 1;
          }
          else {
            firstCount--;
            secondCount--;
          }
        }

        //vote count and validate stage
        firstCount = 0;
        secondCount = 0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==firstCandidate) firstCount++;
          else if(nums[i]==secondCandidate) secondCount++;
        }

        // result declaration
        vector<int> res;
        if(firstCount>nums.size()/3) res.push_back(firstCandidate);
        if(secondCount>nums.size()/3) res.push_back(secondCandidate);

        return res;
    }
};