class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        unordered_map<string, pair<int,  int>> mp, mp1;

        for(int i=0;i<m;i++){
            int cnt1=0, cnt0=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) cnt0++;
                else cnt1++;
            }
            //cout<<cnt0<<" "<<cnt1<<endl;
            mp[to_string(i)] = {cnt0, cnt1}; //row
        }

        for(int i=0;i<n;i++){
            int cnt1=0, cnt0=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]==0) cnt0++;
                else cnt1++;
            }
            //cout<<cnt0<<" "<<cnt1<<endl;
            mp1[to_string(i)] = {cnt0, cnt1};//col
        }

        vector<vector<int>> res(m, vector<int> (n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<mp[to_string(i)].second<<" "<<mp1[to_string(j)].second<<" "<<mp[to_string(i)].first<<" "<<mp1[to_string(j)].first<<endl;


                int a = mp[to_string(i)].second;
                int b = mp1[to_string(j)].second;
                int c = mp[to_string(i)].first;
                int d = mp1[to_string(j)].first;

                res[i][j] = a+b-c-d;
            }
        }

        return res;
    }
};
