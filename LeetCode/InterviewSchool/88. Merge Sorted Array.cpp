class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m+n-1, j = m-1, k=n-1;
        while(j>=0 and k>=0) {
            if(nums1[j]>nums2[k]){
                nums1[i] = nums1[j];
                j--;
            }
            else {
                nums1[i] = nums2[k];
                k--;
            }
            i--;
        }
        while(j>=0){
            nums1[i] = nums1[j];
            i--;
            j--;
        }
        while(k>=0){
            nums1[i] = nums2[k];
            k--;
            i--;
        }
    }
};
