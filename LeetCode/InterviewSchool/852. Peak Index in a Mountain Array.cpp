class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        ///straight forward method
       /* int mx = INT_MIN, index = 0;
        for(int i=0;i<arr.size();i++){
            if(mx<arr[i]) {
                mx = arr[i];
                index = i;
            }
        }
        
        return index;*/
        
        
        ///O(Log(n)) solution: Binary Search : 1, 2, 3, 4, 2, 1
        
        int left = 0, right = arr.size()-1, mid;
        while(left<right){
            mid = (left+right)/2;
            
            if(arr[mid]<arr[mid+1]){
                left = mid+1;
            }
            else right = mid;
        }
        
        return left;
    }
};
