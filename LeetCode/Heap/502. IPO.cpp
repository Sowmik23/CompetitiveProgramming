502. IPO
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>> project;
        for(int i=0;i<profits.size();i++){
            project.push_back({capital[i], profits[i]});
        }

        sort(project.begin(),  project.end());
        priority_queue<int> pq;

        int i = 0;

        while(k){
            while(i<project.size() and project[i].first<=w){
                pq.push(project[i].second);
                i++;
                //if(pq.size()>k) pq.pop();
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop(); 
           }  
           k--;
        }
        return w;
    }
};