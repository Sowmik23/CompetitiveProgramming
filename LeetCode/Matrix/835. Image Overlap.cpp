class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        vector<pair<int, int>> im1,im2;

        int n = img1.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1) im1.push_back({i, j});
                if(img2[i][j]==1) im2.push_back({i, j});
            }
        }

        unordered_map<string, int> mp;

        for(int i=0;i<im1.size();i++){
            for(int j=0;j<im2.size();j++){
                string str = to_string(im1[i].first-im2[j].first)+" "+to_string(im1[i].second-im2[j].second);
                mp[str]++;
            }
        }

        int res = 0;
        for(auto& m:  mp){
            res = max(res, m.second);
        }
        return res;
    }
};
