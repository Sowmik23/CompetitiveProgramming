class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        //simply do merge sort ;) and count inversion for each number
        
        vector<pair<int, int>> arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i], i});
        }
        
        vector<int> ans(nums.size(), 0);
        
        mergesort(0, nums.size()-1, arr, ans);
        
        return ans;
    }
private:
//     void mergeSort(vector<pair<int, int>> &modifiedNums, vector<int> &res, int l, int r){
//         int mid;
//         if(l<r){
//             mid = l+(r-l)/2;
            
//             mergeSort(modifiedNums, res, l, mid);
//             mergeSort(modifiedNums, res, mid+1, r);
            
//             merge(modifiedNums, res, l, mid, r);
//         }
//     }
                 
//     void merge(vector<pair<int, int>> &modifiedNums, vector<int> &res, int l, int m, int r){
        
//         vector<pair<int, int>> tmp(r-l+1);
//         int i = l;
//         int j = m+1;
//         int k = 0;
        
//         while(i<=m and j<=r){
//             if(modifiedNums[i].first<=modifiedNums[j].second){
//                 tmp[k++] = modifiedNums[i++];
//             }
//             else {
//                 res[modifiedNums[j].second] += m-i+1;
//                 tmp[k++] = modifiedNums[j++];
//             }
//         }
//         while(i<=m){
//             tmp[k++] = modifiedNums[i++];
//         }
//         while(j<=r){
//             tmp[k++] = modifiedNums[j++];
//         }
                    
//         for(int i=l;i<=r;i++){
//             modifiedNums[i] = tmp[i-l];
//         }
//     }
    void mergesort(int low,int high,vector<pair<int,int>>&arr,vector<int>&ans)
    {
        if(low<high)
        {
            int mid=low+(high-low)/2;

            mergesort(low,mid,arr,ans);
            mergesort(mid+1,high,arr,ans);

            merge(low,mid,high,arr,ans);
        }
    }
    
    void merge(int low,int mid,int high,vector<pair<int,int>>&arr,vector<int>&ans)
    {
        vector<pair<int,int>>temp(high-low+1);

        int i=low;
        int j=mid+1;
        int k=0;

        while(i<=mid and j<=high)
        {
           if(arr[i].first<=arr[j].first)
           {
               temp[k++]=arr[j++];
           }
           else
            {
               ans[arr[i].second]+=high-j+1;
               temp[k++]=arr[i++];
            }
        }
        while(i<=mid)
        {
            temp[k++]=arr[i++];
        }
        while(j<=high)
        {
            temp[k++]=arr[j++];
        }
        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
    }
};
