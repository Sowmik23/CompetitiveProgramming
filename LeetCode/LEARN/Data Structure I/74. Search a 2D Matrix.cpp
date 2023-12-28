class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        //Time: O(n=m)
        /*
        int m = matrix.size();
        int n = matrix[0].size();

        int i=0, j=n-1;
        while(i<m and j>=0){
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
        */

        //Binary Search
        int m = matrix.size();
        int n = matrix[0].size();

        //trick:
        //convert m*n matrix into an array :  matrix[x][y] => arr[x*n+y];
        //converst an array to matrix: arr[x] => matrix[x/n][x%n];

        int l = 0, r = m*n-1;
        while(l!=r){
            int mid = (l+r-1)/2;
            if(matrix[mid/n][mid%n]>=target){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return matrix[r/n][r%n]==target;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {


        // Think this sorted matrix as sorted array

        int row = matrix.size();
        int col = matrix[0].size();

        int left = 0;
        int right = row*col - 1;

        while(left<=right){
            int mid = (left+right)/2;

            if(matrix[mid/col][mid%col]==target) return true;

            if(matrix[mid/col][mid%col]<target){
                left = mid+1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};
