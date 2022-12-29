class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {

        priority_queue<int, vector<int> , greater<int>> pq;
        for(int i=0;i<capacity.size();i++){
            pq.push(capacity[i]-rocks[i]);
        }

        int res = 0;
        while(!pq.empty()){
            int x = pq.top();
            if(x==0) res++;
            else if(additionalRocks>=x){
                additionalRocks-=x;
                res++;
            }
            else break;
            pq.pop();
        }

        return res;
    }
};
