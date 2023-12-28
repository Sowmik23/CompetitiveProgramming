// 914. X of a Kind in a Deck of Cards
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        
        unordered_map<int, int> mp;
        for(auto& dec: deck){
            mp[dec]++;
        }

        vector<int>gcds(mp.size());
        for(auto& m: mp){
            gcds.push_back(m.second);
        }

        int res = gcds[0];
        for(int i=1;i<gcds.size();i++){
            res = gcd(gcds[i], res);
        }
        
        return res>1;
    }
private:
    int gcd(int a,int b) {
        int temp;
        while(b > 0) {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};