// 2766. Relocate Marbles
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        
       map<int, int> mp;
       for(auto& num: nums) mp[num] = 1;

       for(int i=0;i<moveFrom.size();i++){
           int from = moveFrom[i];
           int to = moveTo[i];
           mp.erase(from);
           mp[to] = 1;
       }
       vector<int> res;
       for(auto& m: mp){
           res.push_back(m.first);
       }
       return res;
    }
};