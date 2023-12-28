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

        int m = matrix.size();
        int n = matrix[0].size();

        int j=n-1, i = 0;
        while(j>=0 and i<m){

            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target) j--;
            else if(matrix[i][j]<target) i++;
        }

        return false;
    }
};
