class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        
        //sort the array based on x_end 
        sort(points.begin(), points.end(), comp);

        int cnt = 0;
        for(int i=0;i<points.size();){
           //cout<<points[i][0]<<" "<<points[i][1]<<endl;
            
            int x = points[i][1];
            //cout<<"x: "<<x<<endl;
            cnt++;
            int j = i+1;
            for(;j<points.size();){
                if(points[j][0]<=x and points[j][1]>=x) {
                    //cnt++;
                    j++;
                }
                else {
                    break;
                }
            }
            i = j;
        }
        
        return cnt;
    }
};
