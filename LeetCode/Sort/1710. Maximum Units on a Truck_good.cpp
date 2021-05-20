bool comp(vector<int> a, vector<int> b){
    return a[1]>b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
     
        //this sorting approach is too much time and memory consuming
        // sort(boxTypes.begin(), boxTypes.end(), comp);
        
        // bothe are same : but this is too much faster and memory efficient
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, vector<int> &b){
            return a[1]>b[1];
        });
        
        
        // for(int i=0;i<boxTypes.size();i++){
        //     for(int j=0;j<boxTypes[i].size();j++){
        //         cout<<boxTypes[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int max_units = 0;
        for(int i=0;i<boxTypes.size() and truckSize!=0;i++){
            if(boxTypes[i][0]<=truckSize){
                truckSize-=boxTypes[i][0];
                max_units+=boxTypes[i][0]*boxTypes[i][1];
            }
            else {
                max_units+=truckSize*boxTypes[i][1];
                truckSize=0;
            }
        }
        
        
        
        
        return max_units;
    }
};
