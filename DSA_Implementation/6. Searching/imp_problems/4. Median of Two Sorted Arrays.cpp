class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        ///Naive or Brute force approach
        ///Time: O(n+m)
      /*  
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
        
        */
        
        
        
        ///Another a little tricky efficient approach:
        //Time: O(log(min(n, m)))
        
        
        //binary search on smaller array
       // return Solution(nums1, nums2);
       
        
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int n = nums1.size();
        int m = nums2.size();
        
        int low = 0, high = n;
        while(low<=high)
        {
            int partitionX = (low+high)/2;
            int partitionY = (n+m+1)/2 - partitionX;
            
            int maxLeftX = (partitionX==0) ? INT_MIN : nums1[partitionX-1];
            int minRightX = (partitionX==n) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY==0) ? INT_MIN : nums2[partitionY-1];
            int minRightY = (partitionY==m) ? INT_MAX : nums2[partitionY];
            
            
            if(maxLeftX<=minRightY and maxLeftY<=minRightX){
                if((n+m)%2==0){
                    return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2.0;
                }
                else {
                    return (double) max(maxLeftX, maxLeftY);
                }
            }
            else if(maxLeftX>minRightY) {
                high = partitionX - 1;
            }
            else {
                low = partitionX + 1;
            }
        }        
     
        return 0.0;
    }
    
// private:
//     double Solution(vector<int> &nums1, vector<int> &nums2){
        
//         if(nums1.size()>nums2.size()){
//             return Solution(nums2, nums1);
//         }
        
//         int n = nums1.size();
//         int m = nums2.size();
        
//         int low = 0, high = n-1;
//         while(low<high)
//         {
//             int partitionX = (low+high)/2;
//             int partitionY = (n+m+1)/2 - partitionX;
            
//             int maxLeftX = (partitionX==0) ? INT_MIN : nums1[partitionX-1];
//             int minRightX = (partitionX==n) ? INT_MAX : nums1[partitionX];
            
//             int maxLeftY = (partitionY==0) ? INT_MIN : nums2[partitionY-1];
//             int minRightY = (partitionY==m) ? INT_MAX : nums2[partitionY];
            
            
//             if(maxLeftX<=minRightY and maxRightY<=minRightX){
//                 if((n+m)%2==0){
//                     return (double)(max(maxLeftX, maxRightY) + min(minLeftX, minRightY))/2.0;
//                 }
//                 else {
//                     return (double) max(maxLeftX, maxRightY);
//                 }
//             }
//             else if(maxLeftX>minRightY) {
//                 hight = partitionX - 1;
//             }
//             else {
//                 low = partitionX + 1;
//             }
//         }        
//     }
};
