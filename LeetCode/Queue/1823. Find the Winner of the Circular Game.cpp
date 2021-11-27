class Solution {
public:
    int findTheWinner(int n, int k) {
        
        //1 2 3 4 5 | 1 3 5 3 
        //Technique: use queue 
        
        //This is actually josephus problem
        //Time: O(n*k)
    
        queue<int> q;
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        
        while(q.size()>1){
            int cnt=1;
            while(cnt<k){
                int front = q.front();
                q.push(front);
                q.pop();
                
                cnt++;
            }
            q.pop();
        }
        
        return q.front();
    }
};
