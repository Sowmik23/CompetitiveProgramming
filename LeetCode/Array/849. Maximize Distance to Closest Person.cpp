class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int mx = 1;
        int i = 0;
        
        while(seats[i]==0) i++;
        
        mx = max(mx, i);
        
        while(i<seats.size()){
            while(i<seats.size() and seats[i]==1) i++;
            
            int cnt = 0;
            int j = i;
            while(i<seats.size() and seats[i]==0){
                i++;
                cnt = i-j;
                if(i==seats.size()) mx = max(mx, cnt);
            }
            if(cnt%2==1) mx = max(mx, cnt/2 + 1);
            else mx = max(mx, cnt/2);
        }
        
        return mx;
    }
};
