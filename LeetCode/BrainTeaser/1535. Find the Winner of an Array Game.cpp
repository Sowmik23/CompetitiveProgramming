// 1535. Find the Winner of an Array Game

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        /*
        unordered_map<int, int> mp;
        int n = arr.size();
        int i = 1;
        int j = 0;
        int last = n;

        while(true){
            if(arr[j]>arr[i]){
                mp[arr[j]]++;
                i++;
                arr.push_back(arr[i]);
            }
            else {
                arr.push_back(arr[i]);
                j = i;
                mp[arr[j]]++;
                i++;
            }
            if(mp[arr[j]]>=k) return arr[j];
        }
        return -1;
        */

        int n = arr.size();
        int res = arr[0];
        int score = 0;
        for(int i=1;i<n;i++){
            if(res>arr[i]){
                score++;
            }
            else {
                if(score>=k) return res;
                res = arr[i];
                score = 1;
            }
        }
        return res;
    }
};