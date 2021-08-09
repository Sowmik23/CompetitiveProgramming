class Solution {
public:
    int thirdMax(vector<int>& nums) {
   
        //Time: O(n)
        //Space: O(1)
        //Another approaches---> priority queue, using set, sorting, quick select algorithm
        
        long long firstMax = LONG_MIN, secondMax = LONG_MIN, thirdMax = LONG_MIN;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            }
            else if(nums[i]<firstMax and nums[i]>secondMax){
                thirdMax = secondMax;
                secondMax = nums[i];
            }
            else if(nums[i]<secondMax and nums[i]>thirdMax){
                thirdMax = nums[i];
            }
        } 
        if(thirdMax!=LONG_MIN) return thirdMax;
        else return firstMax;
    }
};
        
        /*Don't think here quickSelect algorithm */
//         int k = 3; ///here k = 3 as we select third max number from the nums array
//         int ans = quickSelect(nums, 0, nums.size()-1, nums.size()-k);
//         return ans;
//     }
    
    
// private:
//     int quickSelect(vector<int> &nums, int l, int r, int k){
        
//         if(l<=r){
//             int pivotIndex = partition(nums, l, r);
            
//             if(pivotIndex==k) return nums[pivotIndex];
//             else if(pivotIndex<k){
//                 quickSelect(nums, l, pivotIndex-1, k);
//             }
//             else {
//                 quickSelect(nums, pivotIndex+1, r, k);
//             }
//         }
        
//         return nums[0];
//     }
    
//     int partition(vector<int> &nums, int l, int r){
//         int pivot = nums[r];
//         int partitionIdx = l;
        
//         for(int i=l;i<r;i++){
//             if(nums[i]<=pivot){
//                 swap(nums[i], nums[partitionIdx]);
//                 partitionIdx++;
//             }
//         }
//         swap(nums[partitionIdx], nums[r]);
        
//         return partitionIdx;
//     }
//};
