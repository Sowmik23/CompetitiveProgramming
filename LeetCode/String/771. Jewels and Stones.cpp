class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
     /*   vector<char> v;
        for(int i=0;i<jewels.size();i++){
            v.push_back(jewels[i]);
        }
        
        int cnt=0;
        vector<char>::iterator it;
        for(int i=0;i<stones.size();i++){
            it = find(v.begin(), v.end(), stones[i]);
            if(it!=v.end()) cnt++;
        }*/
        
        unordered_set<char> ust;
        for(auto i: jewels){
            ust.insert(i);
        }
        
        int cnt =0;
        for(auto i: stones){
            if(ust.find(i)!=ust.end()) cnt++;
        }
        
        return cnt;
    }
};
