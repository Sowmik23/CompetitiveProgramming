class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
       
       /* 
        priority_queue<int> pqP;
        priority_queue<int, vector<int>, greater<int>> pqN;
        
        for(int i=0;i<nums.size();i++){
           if(nums[i]<0) pqP.push(nums[i]);
           else pqN.push(nums[i]);
        //pqP.push(nums[i]);
        }
        
        int x = INT_MIN, y = INT_MIN;
        
        if(!pqP.empty()){
            x = pqP.top();
        }
        if(!pqN.empty()){
            y = pqN.top();
        }
        
        cout<<x<<" "<<y<<endl;
        
        if(x==INT_MIN) return y;
        if(y==INT_MIN)  return x;
        
        int mnN = 0-x;
        int mnP = y - 0;
        if(mnN<mnP) return x;
        return y;
        
        */
        
		int res = INT_MAX, distance = INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            if(distance>abs(nums[i]) or (abs(nums[i])==distance and nums[i]>res)){
                distance = abs(nums[i]);
                res = nums[i];
            }
        }

        return res;
    }
};

    }
};
