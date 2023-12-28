// 791. Custom Sort String
class Solution {
public:
    string customSortString(string order, string s) {
        
        unordered_map<char, int> ordermap;
        for(int i=0;i<order.size();i++){
            ordermap[order[i]] = i;
        }

        sort(s.begin(), s.end(), [&ordermap](auto& a, auto& b){
            return ordermap[a]<ordermap[b];
        });
        return s;
    }
};