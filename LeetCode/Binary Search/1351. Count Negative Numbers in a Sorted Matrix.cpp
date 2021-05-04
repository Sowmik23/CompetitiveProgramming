class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        //brute force O(n*m) 
        /*int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]<0) cnt++;
            }
        }
        return cnt; */
        
        
        //counting each rows negative numbers: O(n*logm)
        /*int cnt=0;
        for(int i=0;i<grid.size();i++){
            vector<int> tmp(grid[i].begin(), grid[i].end());
            
            cnt+=binarySearch(tmp);
        }
        return cnt;
        */
        
        //Two pointers: O(n+m)
        int n = grid.size();
        int m = grid[0].size();
        int i=0, ans=0, j = m-1;
        while(i<n){
            if(j>=0 and grid[i][j]<0){
                j--;
            }
            else {
                i++;
                
                ans+=(m-j-1);
               // cout<<ans<<endl;
                j = m-1;
            }
        }
        return ans;
        
    }
    
    private:
    int binarySearch(vector<int> v){
        int cnt=-1, start=0, end = v.size()-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(v[mid]<0) {
                cnt = mid;
                end = mid-1;
            }
            else start = mid + 1;
        }
        if(cnt==-1) return 0;
        else cnt = v.size()-cnt;
        return cnt;
    }
};
