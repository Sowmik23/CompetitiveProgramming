class Solution {
public:
    int jump(vector<int>& nums) {
        
     //bfs problem: just go level by level and count total number of level :)
        //level means max range in each step
        
        int mx = 0;
        int currentLast = 0;
        int level = 0;
        
        for(int i=0;i<nums.size()-1;i++){
            if(i+nums[i]>mx) {
                mx = i+nums[i];
            }
            if(i==currentLast) {
                level++;
                currentLast = mx;
            }
        }
        
        return level;
    }
};
