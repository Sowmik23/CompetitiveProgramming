class Solution {
public:
    int fillCups(vector<int>& amount) {
        
        priority_queue<int> pq;
        
        pq.push(amount[0]);
        pq.push(amount[1]);
        pq.push(amount[2]);
        
        int cnt = 0;
        
        int g1 = 0;
        while(!pq.empty()){
            g1 = pq.top();
           // cout<<g1<<endl;
            pq.pop();
            
            int g2 = pq.top();
            pq.pop();
            if(g2>0){
                cnt++;
                g2--;
                g1--;
                pq.push(g1);
                pq.push(g2);
            }
            else break;
        }
        cnt+=g1;
        
        return cnt;
    }
};
