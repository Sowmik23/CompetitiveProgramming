class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        ////Approach-01: using priority queue in matrix
        //Time: n^2logk
      /*  priority_queue<int> pq;
        
        for(int i=0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                pq.push(matrix[i][j]);
                
                if(pq.size()>k) pq.pop();
            }
        }
        
        return pq.top();
        */
        
        ///Approach-02: Binary Search
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = matrix[0][0], high = matrix[m-1][n-1]+1;
        
        while(low<high){
            int mid = (low+high)/2;
            int cnt = 0;
            int j = n-1;
            for(int i=0;i<m;i++){
                while(j>=0 and matrix[i][j]>mid){
                    j--;
                }
                cnt+=(j+1);
            }
            if(cnt<k) low = mid+1;
            else high = mid;
        }
        
        return low;
    }
};
