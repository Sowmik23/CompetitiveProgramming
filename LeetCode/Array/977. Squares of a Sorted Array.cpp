class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    //vector<int> res(nums.size());
      /*  int left, right;
        int i=0, j;
        
        if(nums[nums.size()-1]<0){
            j = nums.size()-1;
            i = nums.size();
        }
        else if(nums[0]>=0) {
            i = 0, j = -1;   
        }
        else {
            while(nums[i]<0){
                i++;
            }
            j = i-1;    
        }
        
        // cout<<i<<" "<<j<<endl;
        
       while(i<nums.size() or j>=0){
            if(j>=0){

                left = nums[j]*nums[j];
            }
            if(i<nums.size()){
                right = nums[i]*nums[i];
                
            }
            if(j>=0 and i<nums.size()){
                if(left<right) {
                    res.push_back(left);
                    j--;
                }
                else {
                    res.push_back(right);
                    i++;
                }
                continue;
            }
            else if(j>=0){
                res.push_back(left);
                j--;
            }
            else if(i<nums.size()){
                res.push_back(right);
                i++;
            }
        }*/
        
        int n = nums.size();
        vector<int> res(n);
        int idx = n-1;
        int left = 0, right = n-1;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                res[idx--] = nums[left]*nums[left];
                left++;
            }
            else {
                res[idx--] = nums[right]*nums[right];
                right--;
            }
        }
        
       
        return res;
    }
}; 
