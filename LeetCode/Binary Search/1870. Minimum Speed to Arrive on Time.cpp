 // 1870. Minimum Speed to Arrive on Time
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        if(dist.size()-1>hour) return -1;

        long mnSpeed = 1;
        long mxSpeed = INT_MAX;
        while(mnSpeed<=mxSpeed){
            long midSpeed = mnSpeed + (mxSpeed-mnSpeed)/2;
            double takenTimeInMidSpeed = makeDecision(midSpeed, dist);
            if(takenTimeInMidSpeed>hour) {
                mnSpeed = midSpeed+1;
            }
            else mxSpeed = midSpeed-1;
        }
        cout<<mnSpeed<<" "<<mxSpeed<<endl;
        return mnSpeed > INT_MAX ? -1 : mnSpeed;
    }
private:
    double makeDecision(long speed, vector<int> &dist){

        int n = dist.size();
        double totalTime = 0;
        for(int i=0;i<n;i++){
            double hr = (double)dist[i]/speed;
            if(i!=n-1) totalTime+=ceil(hr);
            else totalTime+=hr;
        }
        return totalTime;
    }
};