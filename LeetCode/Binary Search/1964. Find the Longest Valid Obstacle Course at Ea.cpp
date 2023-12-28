// 1964. Find the Longest Valid Obstacle Course at Each Position
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        
        int n = obstacles.size();
        vector<int> res(n, 0);
        vector<int> lis;

        for(int i=0;i<obstacles.size();i++){
            int idx = insertIthObstacles(lis, obstacles[i]);
            res[i] = idx+1;
        }
        return res;
    }
private:
    int insertIthObstacles(vector<int> &lis, int obstacle){
        int upperBound = upper_bound(lis.begin(), lis.end(), obstacle) - lis.begin();
        if(upperBound==lis.size()) lis.push_back(obstacle);
        else lis[upperBound] = obstacle;
        return upperBound;
    }
};