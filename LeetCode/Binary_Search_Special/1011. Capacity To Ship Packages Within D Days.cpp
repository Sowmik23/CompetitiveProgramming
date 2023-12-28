// 1011. Capacity To Ship Packages Within D Days
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int left = 0, right = 0;
        for(auto& weight : weights){
            left = max(left, weight);
            right+=weight;
        }

        while(left<right){
            int mid = left+(right-left)/2;
            if(isPossible(weights, mid, days)) right = mid;
            else left = mid+1;
        }
        return left;
    }
private:
    bool isPossible(vector<int> &weights, int mxWeight, int days){

        int cnt = 1;
        int wgts = 0;
        for(auto& w: weights){
            wgts+=w;
            if(wgts>mxWeight){
                cnt++;
                wgts = w;
            }
        }
        return cnt<=days;
    }
};