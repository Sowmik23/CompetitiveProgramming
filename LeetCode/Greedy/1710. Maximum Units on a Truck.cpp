class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        //sort the boxTypes decreasing number of units
        sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]>b[1]; 
        });

        int totalUnits = 0;
        for(auto& t: boxTypes){
            if(truckSize>0){
                if(t[0]<=truckSize){
                    totalUnits +=(t[0]*t[1]);
                    truckSize-=t[0];
                }
                else {
                    totalUnits+=(truckSize*t[1]);
                    truckSize = 0;
                }
            }
            else break;
        }
        
        return totalUnits;
    }
};
