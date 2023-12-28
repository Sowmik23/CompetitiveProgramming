class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        int sum = 0;
        priority_queue<int> pq;

        for(auto& p: piles){
            sum+=p;
            pq.push(p);
        }

        int cut = 0;
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            int y = floor((x+1)/2);
            cut+=(x-y);
            k--;
            if(k==0) break;
            pq.push(y);
        }
        return sum-cut;
    }
};
