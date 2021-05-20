class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        long long sum =0;
        priority_queue<long long> pq;
        for(auto i: target) {
            sum+=i;
            pq.push(i);
        }
        long long top;
        
        while(pq.top()!=1){
            top = pq.top();
           // cout<<top<<endl;
            pq.pop();
            if(top<1) return false;
            
            sum-=top;
            
            if(top<=sum or sum<1) return false;
            top = top%sum;
            
            sum+=top;
            pq.push(top ? top:sum);
        }
        return true;
        // 8 5 = 13 5
        // 3 5 = 5+3 = 8-5 = 3
        // 3 2 = 3+2 = 5-3 = 2
        // 1 2 = 2+1 = 3-2 = 1
    }
};
