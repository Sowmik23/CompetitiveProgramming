// 1095. Find in Mountain Array

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        //binary search

        int n = mountainArr.length();
        int left = 0, right = n-1;

        //just 3 binary search
        // one for finding pick index
        // second on left increasing subarray
        // third on right decreasing subarray

        while(left<right){
            int mid = left + (right-left)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)) left = mid + 1;
            else right = mid;
        }
        int pickIdx = left;
        cout<<"pick index: "<<pickIdx<<endl;

        //binary search on left increasing subarray
        left = 0;
        right = pickIdx;
        while(left<=right){
            int mid = left + (right-left)/2;
            int x = mountainArr.get(mid);
            if(x<target) left = mid + 1;
            else if(x>target) right = mid -1;
            else return mid;
        }

        //binary search on right decreasing subarray
        left = pickIdx;
        right = n-1;
         while(left<=right){
            int mid = left + (right-left)/2;
            int x = mountainArr.get(mid);
            if(x>target) left = mid + 1;
            else if(x<target) right = mid - 1;
            else return mid;
        }

        return -1;
    }
private:
    int res = INT_MAX;
};