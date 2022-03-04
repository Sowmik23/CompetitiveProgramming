class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        
        //initial thought: pascal triangle
          //           1
          //        1      1
          //       1  2  2   1
          //     1   3  4  3   1
          //   1   4   7  7  4   1
          // 1   5   11  14  11  5  1
        
            //Approach: Dynamic Programming...
            // Time: O(n^2)
        
            double arr[101][101] = {0.0};
            
            arr[0][0] = poured;
            for(int i=0;i<=query_row;i++){
                for(int j=0;j<=i;j++){
                    //if glass is poured/overflowed
                    if(arr[i][j]>1){
                        arr[i+1][j] += (arr[i][j]-1)/2.0;
                        arr[i+1][j+1] += (arr[i][j]-1)/2.0;
                        arr[i][j] = 1;
                    }
                }
            }
        
        
            return arr[query_row][query_glass];
        }
};
