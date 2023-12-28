// 1296. Divide Array in Sets of K Consecutive Numbers
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        //Time: O(n)
        //Space: O(n)
        map<int, int> mp;
        for(auto& num: nums) mp[num]++;

        int cnt = 0;
        while(mp.size()>0){
            map<int, int> tmp = mp;
            cnt = 0;
            int prev = -1;

            for(auto& m: tmp){
                cnt++;
                //cout<<m.first<<" "<<m.second<<endl;
                if(prev==-1 and mp[m.first]>0) {
                    prev = m.first;
                }
                else {
                    if(mp[m.first]>0){
                        if(m.first-prev!=1) return false;
                        prev = m.first;
                    }
                }
                mp[m.first]--;
                if(mp[m.first]==0) mp.erase(m.first);
                if(cnt==k) break;
            }
        }
        return cnt%k==0;
    }
};