// 781. Rabbits in Forest
class Solution {
public:
    int numRabbits(vector<int>& answers) {

        int res = 0;
        unordered_map<int, int> mp;
        for(auto& num: answers){
            if(mp[num]==0) {
                res+= num+1; //new color
            }
            mp[num]++;
            if(mp[num]==num+1) mp[num] = 0; //color fully counted
        }   
        return res;
    }
};
