class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        //Memory Limit Exceed
        /*
        sort(tiles.begin(), tiles.end());
        //queue<int> q;
        
        vector<int> arr(INT_MAX, 0);
        int cnt = 0;
        
        for(int i=0;i<tiles.size();i++){
            long x = tiles[i][0];
            long y = tiles[i][1];
            
            if(y-x+1>=carpetLen) return carpetLen;
            
            for(int j=x;j<=y;j++){
                arr[j] = 1;
            }
        }
        
        for(int i=0;i<carpetLen;i++){
            if(arr[i]==1) cnt++;
        }
        
        int mx = cnt;
        for(int i=carpetLen;i<arr.size();i++){
            if(arr[i]==1) cnt++;
            if(arr[i-carpetLen]==1) cnt--;
            mx = max(mx, cnt);
            
        }
        
        return mx;
    */    
        
        sort(tiles.begin(), tiles.end());
        int mx = 0;
        
        long x = tiles[i][0];
        long y = tiles[i][1];
        if(y-x+1>=carpetLen) return carpetLen;
        mx = y-x+1;
        
        for(int i=1;i<tiles.size();i++){
            int gap = tiles[i][0] - y - 1;
            
            x = tiles[i][0];
            y = tiles[i][1];
            
            if(y-x+1>=carpetLen) return carpetLen;
            
            
            
        }
    
        return mx;
    }
};
