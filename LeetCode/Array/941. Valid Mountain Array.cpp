class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size()<3) return false;
        
        int i = 1;
        
        bool flag = false;
        bool flag2 = false;
        bool f = false;
        
        for(;i<arr.size();){
            if(arr[i]>arr[i-1]){
                flag = true;
                i++;
            } 
            else break;
        }
        
        for(int j=i;j<arr.size();){
            if(arr[j-1]>arr[j]){
                j++;
                f = true;
            } 
            else {
                flag2 = true;
                break;
            }
        }
        
        if(flag==false or flag2 or !f) return false;
        return true;
    }
};
