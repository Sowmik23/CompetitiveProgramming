class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        return quickSort(nums, 0, nums.size()-1, nums.size()-k+1);
    }
    
private:
    int quickSort(vector<int> &nums,int l, int r, int k){
        if(l<=r){
            int partitionIndex = partition(nums, l, r);
            
            if(partitionIndex==k-1) return nums[partitionIndex];
            if(partitionIndex<k-1) return quickSort(nums, partitionIndex+1, r, k);
            else return quickSort(nums, l, partitionIndex-1, k);
        }
        
        return NULL;
    }
    
    int partition(vector<int> &nums, int l, int r){
        int pivotIndex = l;
        int val = nums[r];
        for(int i=l;i<r;i++){
            if(nums[i]<=val){
                swap(nums[i], nums[pivotIndex]);
                pivotIndex++;
            }
        }
        swap(nums[pivotIndex], nums[r]);
        return pivotIndex;
    }
};
