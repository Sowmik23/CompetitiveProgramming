class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int m = matrix.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // for(int i=0;i<m;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<m;i++){
            for(int j=0;j<m/2;j++){
                swap(matrix[i][j], matrix[i][m-j-1]);
            }
        }

        // cout<<"Final Output: "<<endl;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<matrix[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
    }
};




class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        /// In-place swaping : 90 degree rotation of a nxn matrix

        for(int i=0;i<n/2+n%2;i++){
            for(int j=0;j<n/2;j++){
                int tmp = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];
                matrix[i][j] = tmp;
            }
        }

    }
};
