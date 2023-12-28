// 403. Frog Jump
class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        //dynamic programming
        int n = stones.size();
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) mp[stones[i]] = i;
        
        //recursive: TLE
        // return recursive(stones, mp, 0, 0);

        //recursion with memoization
        vector<vector<int>> memo(n+1, vector<int> (n+1, -1));
        return recursionWithMemo(stones, mp, memo, 0, 0);
    }
private:
    bool recursive(vector<int> &stones, unordered_map<int, int> &mp, int index, int prevStone){

        if(index==stones.size()-1) return true;
        if(index>=stones.size()) return false;
        
        int a = prevStone -1;
        int b = prevStone;
        int c = prevStone+1;
        bool x = false, y = false, z = false;
        if(a>0 and mp.find(stones[index]+a)!=mp.end()){
            x = recursive(stones, mp, mp[stones[index]+a], a);
        }
        if(b>0 and mp.find(stones[index]+b)!=mp.end()){
            y = recursive(stones, mp, mp[stones[index]+b], b);
        }
        if(c>0 and mp.find(stones[index]+c)!=mp.end()){
            z = recursive(stones, mp, mp[stones[index]+c], c);
        }
        return (x or y or z);
    }
    bool recursionWithMemo(vector<int> &stones, unordered_map<int, int> &mp, vector<vector<int>> &memo, int index, int prevStone){

        if(index==stones.size()-1) return true;
        if(index>=stones.size()) return false;
        
        if(memo[index][prevStone]!=-1) return memo[index][prevStone];
        int a = prevStone -1;
        int b = prevStone;
        int c = prevStone+1;
        bool x = false, y = false, z = false;
        if(a>0 and mp.find(stones[index]+a)!=mp.end()){
            x = recursionWithMemo(stones, mp, memo, mp[stones[index]+a], a);
        }
        if(b>0 and mp.find(stones[index]+b)!=mp.end()){
            y = recursionWithMemo(stones, mp, memo, mp[stones[index]+b], b);
        }
        if(c>0 and mp.find(stones[index]+c)!=mp.end()){
            z = recursionWithMemo(stones, mp, memo, mp[stones[index]+c], c);
        }
        return memo[index][prevStone] = (x or y or z);
    }
};