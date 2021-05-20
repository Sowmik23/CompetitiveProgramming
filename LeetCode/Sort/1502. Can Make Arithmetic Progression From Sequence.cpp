class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
     
        sort(arr.begin(), arr.end());
        
        for(int i=1;i<arr.size()-1;i++){
            
            int diff1 = arr[i] - arr[i-1];
            int diff2 = arr[i+1] - arr[i];
            
            if(diff1!=diff2) return false;
        }
        return true;
    }
};
