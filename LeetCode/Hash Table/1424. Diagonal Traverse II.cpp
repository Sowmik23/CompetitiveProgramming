// 1424. Diagonal Traverse II

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        
        /*
        //TLE

        vector<int> res;
        int m = nums.size();
        int n = m;

        if(m==1) return nums[0];

        for(int i=0;i<m;i++){
            n = n<nums[i].size() ? nums[i].size() : n;
            int x = i;
            for(int j=0;j<m and x>=0;j++){
                if(j<nums[x].size()){
                    res.push_back(nums[x][j]);
                }
                x--;
            }
        }
        // cout<<m<<" "<<n<<endl;
        for(int i=1;i<n;i++){
            int x = m-1;
            for(int j=i;j<n and x>=0;j++){
                if(j<nums[x].size()) res.push_back(nums[x][j]);
                x--;
            }
        }

        return res;
        */

        //Map
        //TIme: O(n)
        unordered_map<int, vector<int>> mp;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=0;j<nums[i].size();j++){
                int key = i+j;
                mp[key].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        int i = 0;
        while(mp.find(i)!=mp.end()){
            for(auto& num: mp[i]){
                res.push_back(num);
            }
            i++;
        }
        return res;

    }
};