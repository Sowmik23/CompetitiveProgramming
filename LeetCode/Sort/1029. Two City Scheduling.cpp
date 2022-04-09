class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b){
           // if(a[0]<a[1]){
           //    if(a[0]<b[0]) return true;
           //    else return false;
           // } 
           //if(a[0]<a[1] and a[0]<=b[0] and b[0]<b[1]) return true;
           
            return (a[1]-a[0])>(b[1]-b[0]);
            return false;
        });
        
    
        
        int limit = costs.size()/2;
        int sum = 0;
        for(int i=0;i<costs.size();i++){
            cout<<costs[i][0]<<" "<<costs[i][1]<<endl;
            if(i<limit) sum+=costs[i][0];
            else sum+=costs[i][1];
        }
        //cout<<sum<<" "<<limit<<endl;
        return sum;
    }
};
