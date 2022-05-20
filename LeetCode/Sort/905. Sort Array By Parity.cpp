class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        //using stl
        sort(nums.begin(), nums.end(), [](int a, int b){
            
            if(a%2!=0) return false;
            return true;
        });
        
        return nums;
    
        //using two pointer
        /*
        int i = 0;
        int j = nums.size()-1;
        while(i<j){
            while(i<j and nums[i]%2==0) i++;
            while(j>i and nums[j]%2==1) j--;
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        
        return nums;
        */
    }
};
