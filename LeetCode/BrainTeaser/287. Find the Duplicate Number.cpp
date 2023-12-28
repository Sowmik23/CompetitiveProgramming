// 287. Find the Duplicate Number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();

        //Approch-01: sorting + Binary Search ? 
        // Time: O(nlogn)
        /*
        sort(nums.begin(), nums.end());
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) return nums[i];
        }
        return -1;
        */

        //Approach-02: if we have permission to modify the input array 
        // Time: O(n)
        /*
        for(int i=0;i<n;i++){
            int x = abs(nums[i]);
            if(nums[x-1]<0) return x;
            nums[x-1] = -nums[x-1];
        }
        return -1;
        */

        //how can we do it in linear time ?
        // YES: Remember hare and tortoise algorithm for linkedlist :) use thissssss!!!!

        // since we know there is a repeated element therefore there will always be a cycle and starting element of the cycle is always the repeated element 

        int slow = nums[0];
        int fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};