class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        
        // Nice question:
        // Intuition: 1. we can divide the number until it is odd(may need multiple operation)
        // Intuition: 2. if we multiply odd with 2 it will be even(one operation)
        
    
        priority_queue<int> pq;
        int res = INT_MAX, mn = INT_MAX;
        
        for(auto& num: nums){
            if(num%2==1) num = num*2;
            
            mn = min(mn, num);
            pq.push(num);
        }
        
        while(pq.top()%2==0){
            res = min(res, pq.top()-mn);
            
            mn = min(mn, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        
        return min(res, pq.top()-mn);
    }
};
