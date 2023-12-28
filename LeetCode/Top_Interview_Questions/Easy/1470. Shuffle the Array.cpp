// 1470. Shuffle the Array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        //using extra space is easy: Time: O(n), Space: O(n)
        /*
        vector<int> res(2*n);
        int j = 0;

        for(int i=0;i<n;i++){
            res[j++] = nums[i];
            res[j++] = nums[n+i];
        }
        return res;
        */

        //but not using extra space is a little bit trickier
        //Time: O(n), Space: O(1)
        
        //Probably the best problem for interview...When interviewer ask to solve it in place... :)

        for(int i=n;i<nums.size();i++){ //multiply by number which is greater than both of num1 and num2.
            nums[i] = nums[i]*1050 + nums[i-n];   //from the nth pos keep both 0 and n'th number encrypted. same as 1 and n+1, 2 and n+2'th positions
        }

        int idx = 0;
        for(int i=n;i<nums.size();i++){
            nums[idx++] = nums[i]%1050; //extract the first number
            nums[idx++] = nums[i]/1050; //extract the 2nd number
        }
        

        return nums;
    }
};