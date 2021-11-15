class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        
        //brute force: Time: O(n^2)
        
//         int cnt = 0;
        
//         while(tickets[k]!=0){
//             for(int i=0;i<tickets.size();i++){
                
//                 if(tickets[i]>0){
//                     tickets[i]--;
//                     cnt++;
//                 }
//                 if(tickets[k]==0) return cnt;
//             }    
//         }
        
//         return cnt;
        
        
        //optimized version
        
        int cnt = 0;
        for(int i=0;i<tickets.size();i++){
            if(i<=k){
                cnt+=min(tickets[i], tickets[k]);
            }
            if(i>k){
                cnt+=min(tickets[i], tickets[k]-1);
            }
        }
        
        
        return cnt;
    }
};
