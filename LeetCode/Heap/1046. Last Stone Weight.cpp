class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        ///implementation of heap using STL: moral of the story: it takes too much time
      /*  make_heap(stones.begin(), stones.end());
        
        int x, y;
        
        while(stones.size()>1) {
            y = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            x = stones.front();
            
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            stones.push_back(y-x);
            push_heap(stones.begin(), stones.end());
            
           
        }
        
        int res = stones.front();
        pop_heap(stones.begin(), stones.end());
        stones.pop_back();

        
        
        return res;*/
        
        ///approach: priority queue
        
        priority_queue<int> pq;
        for(auto i: stones){
            pq.push(i);
        }
        
        int x, y;
        while(pq.size()>1){
            y = pq.top();
            pq.pop();
            
            x = pq.top();
            pq.pop();
            
            
            pq.push(y-x);
        }
        
        return pq.top();
    }
};
