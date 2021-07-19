class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        vector<int> merged(n+m);
        
        int i=0, j=0, k=0;
        while(i<n and j<m){
            if(nums1[i]<=nums2[j]){
                merged[k] = nums1[i];
                i++;
            }
            else {
                merged[k] = nums2[j];
                j++;
            }
            k++;
        }
        while(i<n){
            merged[k++] = nums1[i++];
        }
        while(j<m){
            merged[k++] = nums2[j++];
        }
        
        double median = 0.0;
        if(k%2==1){
            median = merged[k/2];
        }   
        else {
            median = (merged[k/2] + merged[k/2-1])/2.0;
        }    
        
        return median;
    }
};
