// 2462. Total Cost to Hire K Workers
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        /*
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqFirst, pqLast;
        for(int i=0;i<candidates;i++) pqFirst.push({costs[i], i});
        for(int i=n-1;i>=n-candidates;i--) pqLast.push({costs[i], i});

        int i = candidates;
        int j = n-candidates-1;
        long long cost = 0;

        while(!pqFirst.empty() and !pqLast.empty() and k>0){
            auto firstTop = pqFirst.top();
            auto lastTop = pqLast.top();

            if(firstTop.first<=lastTop.first){
                if(firstTop.first==lastTop.first){
                    if(firstTop.second==lastTop.second){
                        cost+=firstTop.first;
                        pqFirst.pop();
                        pqLast.pop();
                    }
                    else if(firstTop.second<lastTop.second){
                        cost+=firstTop.first;
                        pqFirst.pop();
                        if(i<=j) {
                            pqFirst.push({costs[i], i});
                            i++;
                        }
                    }
                    else {
                        cost+=lastTop.first;
                        pqLast.pop();
                        if(i<=j) {
                            pqLast.push({costs[j], j});
                            j--;
                        }
                    }
                }
                else {
                    cost+=firstTop.first;
                    pqFirst.pop();
                    if(i<=j) {
                        pqFirst.push({costs[i], i});
                        i++;
                    }
                }
            }
            else {
                cost+=lastTop.first;
                pqLast.pop();
                if(i<=j) {
                    pqLast.push({costs[j], j});
                    j--;
                }
            }
            k--;
        }
        return cost;
        */

        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pqFirst, pqLast;

        for(int i=0;i<candidates;i++) pqFirst.push(costs[i]);
        // for(int i=n-1;i>=n-candidates;i--) pqLast.push(costs[i]);
        for(int i=max(candidates, n-candidates);i<n;i++) pqLast.push(costs[i]);

        int i = candidates;
        int j = n-candidates-1;
        long long cost = 0;

        for(int idx = 0;idx<k;idx++){
            if(pqLast.empty() or !pqFirst.empty() and pqFirst.top()<=pqLast.top()){
                cost+=pqFirst.top();
                pqFirst.pop();
                if(i<=j){
                    pqFirst.push(costs[i]);
                    i++;
                }
            }
            else {
                cost+=pqLast.top();
                pqLast.pop();
                if(i<=j){
                    pqLast.push(costs[j]);
                    j--;
                }
            }   
        }

        return cost;
    }
};