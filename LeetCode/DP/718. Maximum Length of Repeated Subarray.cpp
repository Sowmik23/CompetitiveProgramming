class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {


        //TLE
        /*
        if(nums1.size()>nums2.size()) return findLength(nums2, nums1);

        unordered_map<int, vector<int>> mp;
        for(int i=0;i<nums2.size();i++) mp[nums2[i]].push_back(i);

        // 1 2 3 4 5 6
        // 2 3 4 1 2 3 4 5 6
        vector<bool> visited(nums2.size()+1, false);
        int mx = 0;
        for(int i=0;i<nums1.size();i++){
            int x = nums1[i];
            if(mp.find(x)!=mp.end()){
                for(auto& k: mp[x]){
                   // cout<<k<<" ";

                    if(k<i and visited[k]) continue;
                    visited[k]  = true;
                    int a = i;
                    int b = k;
                    while(a<nums1.size() and b<nums2.size()){
                        if(nums1[a]!=nums2[b]) break;
                        mx = max(mx, a-i+1);
                        a++;
                        b++;
                    }
                }
               // cout<<endl;
            }
        }
        return mx;
        */

        //I forgot that it it is a sub-problem of longest common substring, my bad 😥
        //recursive approach: TLE
        // int res = 0;
        // recursive(nums1, nums2, nums1.size(), nums2.size(), res);
        // return res;

        //recursion with memoization
        vector<vector<int>> memo(nums1.size(), vector<int> (nums2.size(), -1));
        int res = 0;
        recursionWithMemo(nums1, nums2, memo, nums1.size(), nums2.size(), res);
        return res;
    }
private:
    int recursive(vector<int> &nums1, vector<int> &nums2, int i, int j, int &res){
        if(i==0 or j==0)  return 0;

        int x = 0;
        if(nums1[i-1]==nums2[j-1]) x = 1+recursive(nums1, nums2, i-1, j-1, res);
        recursive(nums1, nums2, i-1, j, res);
        recursive(nums1, nums2, i, j-1, res);
        res = max(res, x);
        return x;
    }

    int recursionWithMemo(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &memo, int i, int j, int &res){
        if(i==0 or j==0) return 0;
        if(memo[i-1][j-1]!=-1) return memo[i-1][j-1];

        int x = 0;
        if(nums1[i-1]==nums2[j-1]) {
            x = 1+recursionWithMemo(nums1, nums2, memo, i-1, j-1, res);
        }
        recursionWithMemo(nums1, nums2, memo, i-1, j, res);
        recursionWithMemo(nums1, nums2, memo, i, j-1, res);
        res = max(res, x);
        return memo[i-1][j-1] = x;
    }
};
