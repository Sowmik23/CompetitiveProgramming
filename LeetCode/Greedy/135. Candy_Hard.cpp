class Solution {
public:
    int candy(vector<int>& ratings) {
        
        
        //maybe choosing stack based solution is hard to implement for this problem
        //So need to move brute force approach
        
        /*
        stack<int> stk;
        
        int res = 0;
        int lastVal = 0 ;
        int lastCnt = 0;
        //4 3 2 2 4 3 2 2 4
        for(int i=0;i<ratings.size();i++){
            if(!stk.empty() and stk.top()>ratings[i]){
                int x = stk.top();
                if(x>lastVal) lastCnt++;
                stk.pop();
                
                res+=lastCnt;
                int tmp = lastCnt;
                while(!stk.empty()){
                    if(x==stk.top()){
                        res+= tmp;
                    }
                    else {
                        tmp++;
                        res+=tmp;
                    }
                    x = stk.top();
                    stk.pop();
                }
            }
            stk.push(ratings[i]);
        }
        
        int x;
        if(!stk.empty()){
            x = stk.top();
            if(x>lastVal) lastCnt++;
            res+=lastCnt;
            stk.pop();
        }
        
        int tmp = lastCnt;
        while(!stk.empty()){
            if(x==stk.top()){
                res+= tmp;
            }
            else {
                tmp++;
                res+=tmp;
            }
            x = stk.top();
            stk.pop();
        }
        
        return res;
        
        */
        
        int res = 0;
        int n = ratings.size();
        vector<int> left(n, 1), right(n, 1);
        
        //4 3 2 2 4 3 2 2 4
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) left[i] = left[i-1] + 1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]) right[i] = right[i+1] + 1;
        }
        
        for(int i=0;i<n;i++){
            res+=max(left[i], right[i]);
        }
        
        return res;
    }
};
