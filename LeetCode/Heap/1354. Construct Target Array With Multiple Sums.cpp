class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        //max pq
        priority_queue<int> pq;
        
        long long sum = 0;
        for(auto& t: target){
            sum+=t;
            pq.push(t);
        }
        
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            if(top==1) break;
            sum -= top;
            
            if(top<=sum or sum<1) return false;
            top = top%sum;
            top  = top!=0 ? top : sum;
            
            sum+=top;
            pq.push(top);
        }
        

        
        return true;
    }
};
