class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        //Approach-01: Greedy
        /*
        int mx = nums[0];
        for(int i=0;i<nums.size();i++){
            if(i<=mx) {
                mx = max(mx, nums[i]+i);
                if(mx>=nums.size()-1) return true;
            }
            else return false;
        }
        
        return false;
        */
        
        //Recursion
        int n = nums.size();
        return ifPossible(nums, n-1, n-2);
        
        
        //Approach-02: DP
        /*
        int n = nums.size();

        if(n==1) return true;
        for(int i=1;i<n-1;i++){
            if(nums[i-1]==0) nums[i] = 0;
            else nums[i] = max(nums[i-1]-1, nums[i]);
        }
        return nums[n-2]>=1;
        */
      
        
        //Approach-02: DP(Top-Down)
        /*
        int n = nums.size();
        if(n==1) return true;
        
        int sink = n-1;
       
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=sink){
                sink = i;
            }
        }
       // cout<<sink<<" "<<source<<endl;
        if(sink==0) return true;
        return false;
        */
        
        
    }
private:
    bool ifPossible(vector<int> &nums, int sink, int i){
        cout<<i<<" "<<sink<<endl;
        if(nums.size()==1) return true;
        
        //if(sink==0) return true;
        if(i<0 and sink==0) return true;
        if(i<0 and sink!=0) return false;
        
        if(i+nums[i]>=sink){
            sink = i;
        }
        i--;
        return ifPossible(nums, sink, i);
    }
};
