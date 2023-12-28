class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        //Bubble sort: TLE
        // * Bubble sort
        // * Time: O(n^2)
        // * Space: O(1)
        // * In-place: yes(extra memory use kore na)
        // * Stable: yes(order thik thake)
        // * class: comparison
        /*
        for(int i=0;i<n;i++){
            bool flag = false;
            for(int j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]) {
                    flag = true;
                    swap(nums[j], nums[j+1]);
                }
            }
            if(flag==false) break;
        }
        */

        //selection sort: TLE
        // * Time: O(n^2) Best case: O(n^2) 
        // * Space: O(1)
        // * In-place: Yes
        // * Stable: NO
        /*
        for(int i=0;i<n;i++){
            int minIdx = i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[minIdx]) minIdx = j;
            }
            swap(nums[i], nums[minIdx]);
        }
        */

        //insertion sort: TLE
        // * Time: O(n^2) , Best case: O(n)
        // * Space: O(1)
        // * In-pace : yes
        // * Stable: yes
        // * Online: yes
        // * Class: comparison 
        /*
        for(int i=0;i<nums.size();i++){
            int prev = i;
            int prevVal = nums[i];
            while(prev>0 and prevVal<nums[prev-1]){
                nums[prev] = nums[prev-1];
                prev--;
            }
            nums[prev] = prevVal;
        }
        */

        //merge sort: Accepted
        // * Time: O(n*logn) => worst, average, best
        // * Space: O(n) => here extra space needed. 
        // * Stable: yes
        // * In-place: No: as need extra space
        // * Class: comparison
        /*
        int left = 0, right = n-1;
        mergeSort(nums, left, right);
        */

        //quick sort: TLE
        // * Time: O(n*logn) : Best & Average : Worst: O(n^2)
        // * Space: O(1): But it is listed as space complexity is: O(logn)
        // * Stable: No
        // * In-place: Yes
        // * Class: Comparison
        // * Method: partitioning
        /*
        int left = 0, right = n-1;
        quickSort(nums, left, right);
        */

        //counting sort: Accepted
        // * Time: O(n+k) : (Best, worst, average same) k is range of elements
        // * Space : O(max range)
        // * Stable : Yes
        // * Class: Non-comparison sort
        // * In-place:  No (it use extra memory)
        
        /*
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }

        vector<int> cnt(mx-mn+1);
        for(int i=0;i<n;i++){
            cnt[nums[i]-mn]++;
        }
        for(int i=1;i<cnt.size();i++){
            cnt[i]+=cnt[i-1];
        }
        vector<int> sortedNums(n);
        for(int i=n-1;i>=0;i--){
            sortedNums[cnt[nums[i]-mn]-1] = nums[i];
            cnt[nums[i]-mn]--;
        }
        for(int i=0;i<n;i++) nums[i] = sortedNums[i];
        */

        //radix sort: Accepted
        // O(d*(n+b))
        /// b = base of the number
        /// d = max length of number
        /// n = total number
        // Time: O(N*d) ==O(N)
        // Auxiliary Space: O(N)
        /*
        int mx1, mx2;
        mx1 = mx2 = INT_MIN;
        vector<int> positiveNums, negativeNums;

        for(int i=0;i<n;i++){
            if(nums[i]>=0) {
                mx1 = max(mx1, nums[i]);
                positiveNums.push_back(nums[i]);            
            }
            else {
                mx2 = max(mx2, abs(nums[i]));
                negativeNums.push_back(abs(nums[i]));
            }
            
        }

        //sort the positive nums first
        for(int exp = 1;mx1/exp>0; exp*=10){
            countingSortForRadixSortHelper(positiveNums, exp);
        }
        //sort the negative nums
        for(int exp = 1;mx2/exp>0; exp*=10){
            countingSortForRadixSortHelper(negativeNums, exp);
        }

        //join negative and positive nums;
        int k = 0;
        for(int i=negativeNums.size()-1;i>=0;i--){
            nums[k++] = -negativeNums[i];
        }
        for(int i=0;i<positiveNums.size();i++){
            nums[k++] = positiveNums[i];
        }
        */

        //bucket sort
        //For large set of floating point numbers
        // Time: O(n+k), Best, Average: O(n), Worst(O^2)
        // Memory: O(n+k)
        // In-Place: No
        // Stable: Yes
        // Class: Comparison based
        /*
        int mx1, mx2;
        mx1 = mx2 = INT_MIN;
        vector<int> positiveNums, negativeNums;

        for(auto& num: nums){
            if(num>=0) {
                mx1 = max(mx1, num);
                positiveNums.push_back(num);            
            }
            else {
                mx2 = max(mx2, abs(num));
                negativeNums.push_back(abs(num));
            }
        }

        processBucket(positiveNums, mx1);
        processBucket(negativeNums, mx2);
    
        int idx = 0;
        for(int i=negativeNums.size()-1;i>=0;i--) nums[idx++] = -negativeNums[i];
        for(int i=0;i<positiveNums.size();i++) nums[idx++] = positiveNums[i];
        */

        //heap sort

        priority_queue<int> pq(nums.begin(), nums.end()); //implement pq and observe heapify part
        int i=nums.size()-1;
        while(!pq.empty()){
            nums[i] = pq.top();
            pq.pop();
            i--;
        }


        return nums;
    }
private:
    void mergeSort(vector<int> &nums, int left, int right){
        if(left<right){
            int mid = left+(right-left)/2;
            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }
    void merge(vector<int> &nums, int left, int mid, int right){
        int n1 = mid-left+1;
        int n2 = right-mid;
        int arr1[n1], arr2[n2];
        for(int i=0;i<n1;i++){
            arr1[i] = nums[left+i];
        }
        for(int i=0;i<n2;i++){
            arr2[i] = nums[mid+1+i];
        }

        int i = 0, j = 0, k = left;
        while(i<n1 and j<n2){
            if(arr1[i]<arr2[j]){
                nums[k] = arr1[i];
                i++;
            }
            else {
                nums[k] = arr2[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            nums[k++] = arr1[i++];
        }
        while(j<n2){
            nums[k++] = arr2[j++];
        }
    }
    void quickSort(vector<int> &nums, int left, int right){
        if(left<right){
            int pivot = partitionRight(nums, left, right);
            quickSort(nums, left, pivot-1);
            quickSort(nums, pivot+1, right);
        }
    }
    int partitionRight(vector<int> &nums, int left, int right){
        int partitionIdx = left;
        int partitionValue = nums[right];
        for(int i=left;i<right;i++){
            if(nums[i]<partitionValue){
                swap(nums[i], nums[partitionIdx]);
                partitionIdx++;
            }
        }
        swap(nums[right], nums[partitionIdx]);
        return partitionIdx;
    }
    void countingSortForRadixSortHelper(vector<int> &nums, int exp){
        int n = nums.size();
        vector<int> cnt(10);

        for(int i=0;i<n;i++){
            cnt[(nums[i]/exp)%10]++;
        }
        for(int i=1;i<10;i++){
            cnt[i]+=cnt[i-1];
        }
        vector<int> sortedNums(n);
        for(int i=n-1;i>=0;i--){
            sortedNums[cnt[(nums[i]/exp)%10]-1] = nums[i];
            cnt[(nums[i]/exp)%10]--;
        }
        for(int i=0;i<n;i++) nums[i] = sortedNums[i];
    }
    void processBucket(vector<int> &nums, int mx){
        int n = nums.size();
        vector<int> bucket[n+1];
        for(int i=0;i<n;i++){
            int bkt = (nums[i])%(n);
            bucket[bkt].push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            sort(bucket[i].begin(), bucket[i].end());
        }
        int idx = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<bucket[i].size();j++){
                nums[idx++] = bucket[i][j];
            }
        }
    }
};