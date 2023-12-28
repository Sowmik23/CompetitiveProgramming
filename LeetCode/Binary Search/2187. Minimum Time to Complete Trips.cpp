// 2187. Minimum Time to Complete Trips
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long left = 1, right = 1LL* *max_element(time.begin(), time.end())*totalTrips;

        while(left<right){
            long long mid = (left+right)/2;
            if(timeEnough(time, mid, totalTrips)) right = mid;
            else left = mid+1;
        }
        return left;
    }
private:
    bool timeEnough(vector<int> &time, long long mid, int totalTrips){
        long long trips = 0;
        for(auto& t: time){
            trips+=mid/t;
        }
        return trips>=totalTrips;
    }
};