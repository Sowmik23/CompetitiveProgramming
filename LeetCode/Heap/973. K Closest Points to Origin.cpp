class Solution {
    
    struct comp{
        bool operator() (pair<double, pair<int, int>> a, pair<double, pair<int, int>> b){
            return a.first>b.first;
        }   
    };
    
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> res;
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, comp > pq;
        
        int x, y;
        for(int i=0;i<points.size();i++){
            
            x = points[i][0];
            y = points[i][1];
            
            double d = calculate_distace(x, y);
            
            //cout<<x<<" "<<y<<" "<<d<<endl;
            pq.push(make_pair(d, make_pair(x,y)));
           // if(pq.size()>k) pq.pop();
        }
        
        
        for(int i=0;i<k;i++){
            // cout<<pq.top().second.first<<" "<<pq.top().second.second<<endl;
            vector<int> tmp;
            tmp.push_back(pq.top().second.first);
            tmp.push_back(pq.top().second.second);
            res.push_back(tmp);
            //res[pq.top().second.first].push_back(pq.top().second.second);
            pq.pop();
        }
        
        
        return res;
    }
    
    private:
    double calculate_distace(int x, int y){
        
        return sqrt(x*x + y*y);
    }
};
