class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        
        unordered_map<int, int> mpR;
        unordered_map<char, int> mpS;
        
        for(int i=0;i<ranks.size();i++){
            mpR[ranks[i]]++;
            mpS[suits[i]]++;
        }
        
        if(mpS.size()==1) return "Flush";
        
        for(auto& i: mpR){
            if(i.second>=3) return "Three of a Kind";
        }
        
        for(auto& i: mpR){
            if(i.second>=2) return "Pair";
        }
        
        return "High Card";
    }
};
