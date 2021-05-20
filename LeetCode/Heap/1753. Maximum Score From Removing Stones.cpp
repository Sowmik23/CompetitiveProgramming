class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        //approach-01: math
        //first sort a, b, c
        int small, mid, high;
        small = min(a, min(b, c));
        high = max(a, max(b, c));
        mid = (a+b+c)-small-high;
        
        // cout<<high<<" "<<mid<<" "<<small<<endl;
        
        if(high>=(mid+small)) return (mid+small);
        else return (high+mid+small)/2;
        
          
        //approach-02: max-heap 
/*        int cnt =0;
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        int x, y;
        while(true){
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            if(x==0 or y==0) break; 
            x--;
            y--;
            cnt++;
            pq.push(x);
            pq.push(y);
        }
        return cnt; */
    }
};
