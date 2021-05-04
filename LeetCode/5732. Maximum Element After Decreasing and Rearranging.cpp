class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        int cnt=0;
       
        
        sort(arr.begin(), arr.end());
        
        //if(arr.size()==1) return 1;
        
        arr[0] = 1;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])>1) {
                arr[i] = arr[i-1]+1;
            }
        }
        //if(cnt==0 or cnt==1) cnt = arr[arr.size()-1];
        
        return arr[arr.size()-1];
    }
};
