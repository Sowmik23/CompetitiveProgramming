class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        //dynamic programming
        // This is a perfect problem for dynamic programming because every 
        // decision we make will affect future decisions.

        //handle the case: if one array's all elements are negative
        int firstMx = INT_MIN;
        int secondMx = INT_MIN;

        int firstMn = INT_MAX;
        int secondMn = INT_MAX;

        for(int i=0;i<nums1.size();i++){
            firstMx = max(firstMx, nums1[i]);
            firstMn = min(firstMn, nums1[i]);
        }

         for(int i=0;i<nums2.size();i++){
            secondMx = max(secondMx, nums2[i]);
            secondMn = min(secondMn, nums2[i]);
        }

        if(firstMx<0 and secondMn>0) return firstMx*secondMn;
        if(secondMx<0 and firstMn>0) return secondMx*firstMn;

        cout<<"pass"<<endl;

        memo = vector(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        return recursive(nums1, nums2, memo, 0, 0);
   
    }
private:
    vector<vector<int>> memo;
    int recursive(vector<int>&nums1, vector<int> &nums2, vector<vector<int>> &memo, int i, int j){

        if(i==nums1.size() or j==nums2.size()) return 0;
        if(memo[i][j]!=0) return memo[i][j];

        int a = (nums1[i]*nums2[j]) + recursive(nums1, nums2, memo, i+1, j+1);
        int mx = max(a, max(recursive(nums1, nums2, memo, i+1, j), recursive(nums1, nums2, memo, i, j+1)));

        return memo[i][j] = mx;
    }
};
