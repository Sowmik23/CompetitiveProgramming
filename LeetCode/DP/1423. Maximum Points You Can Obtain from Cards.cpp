class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     
        int sum = 0;
        for(auto& point: cardPoints){
            sum+=point;
        }
        int left = 0, right = 0;
        
        int minSum = 0;
        int res = INT_MAX;
        k = cardPoints.size()-k;
        
        while(right<k) {
            minSum+=cardPoints[right];
            right++;
        }
        
        while(right<cardPoints.size()){
            res = min(res, minSum);
            minSum -=cardPoints[left];
            minSum+=cardPoints[right];

            left++;  
            right++;
        }
        res = min(res, minSum);
        
        return sum-res;
    }
};
